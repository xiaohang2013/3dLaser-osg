/*
 * Date: 2016.11.29
 * By: Liu
 * Function: Derived class from PrimitiveFunctor and this class is realized by following the TriangleFunctor.
 * Used to get lines array from a drawable.
 * */
#ifndef LINEFUNCTOR
#define LINEFUNCTOR

#include <osg/PrimitiveSet>
#include <osg/Notify>
#include <osg/Array>

namespace osg {

//template<class T>
class LineFunctor : public PrimitiveFunctor/*, public T*/
{
public:

    LineFunctor()
    {
        _vertexArraySize=0;
        _vertexArrayPtr=0;
        _modeCache=0;
        _treatVertexDataAsTemporary=false;

        _linesArray=new Vec3Array;
    }

    virtual ~LineFunctor() {}

    void setTreatVertexDataAsTemporary(bool treatVertexDataAsTemporary) { _treatVertexDataAsTemporary=treatVertexDataAsTemporary; }
    bool getTreatVertexDataAsTemporary() const { return _treatVertexDataAsTemporary; }

    virtual void setVertexArray(unsigned int,const Vec2*)
    {
        notify(WARN)<<"Line Functor does not support Vec2* vertex arrays"<<std::endl;
    }

    virtual void setVertexArray(unsigned int count,const Vec3* vertices)
    {
        _vertexArraySize = count;
        _vertexArrayPtr = vertices;
    }

    virtual void setVertexArray(unsigned int,const Vec4* )
    {
        notify(WARN)<<"Line Functor does not support Vec4* vertex arrays"<<std::endl;
    }

    virtual void setVertexArray(unsigned int,const Vec2d*)
    {
        notify(WARN)<<"Line Functor does not support Vec2d* vertex arrays"<<std::endl;
    }

    virtual void setVertexArray(unsigned int,const Vec3d*)
    {
        notify(WARN)<<"Line Functor does not support Vec3d* vertex arrays"<<std::endl;
    }

    virtual void setVertexArray(unsigned int,const Vec4d* )
    {
        notify(WARN)<<"Line Functor does not support Vec4d* vertex arrays"<<std::endl;
    }

    virtual void drawArrays(GLenum mode,GLint first,GLsizei count)
    {
        if (_vertexArrayPtr==0 || count==0) return;

        switch(mode)
        {
            case(GL_TRIANGLES):
            {
                const Vec3* vlast = &_vertexArrayPtr[first+count];
                for(const Vec3* vptr=&_vertexArrayPtr[first];vptr<vlast;vptr+=3)
                    for(int i=0; i<3; ++i)
                    {
                        int j=(i+1)%3;
                        addLineToLinesArray(*(vptr+i), *(vptr+j));
                    }
                break;
            }
            case(GL_TRIANGLE_STRIP):
            {
                const Vec3* vptr = &_vertexArrayPtr[first];
                for(int i=0;i<count-1;++i)
                {
                    addLineToLinesArray(*(vptr+i), *(vptr+i+1));
                    if(i<count-2) addLineToLinesArray(*(vptr+i), *(vptr+i+2));
                }
                break;
            }
            case(GL_QUADS):
            {
                const Vec3* vlast = &_vertexArrayPtr[first+count];
                for(const Vec3* vptr=&_vertexArrayPtr[first];vptr<vlast;vptr+=4)
                    for(int i=0; i<4; ++i)
                    {
                        int j=(i+1)%4;
                        addLineToLinesArray(*(vptr+i), *(vptr+j));
                    }
                break;
            }
            case(GL_QUAD_STRIP):
            {
                const Vec3* vptr = &_vertexArrayPtr[first];
                for(int i=0;i<count/2-1;++i)
                {
                    addLineToLinesArray(*(vptr+2*i), *(vptr+2*i+1));
                    addLineToLinesArray(*(vptr+2*i), *(vptr+2*i+2));
                    addLineToLinesArray(*(vptr+2*i+1), *(vptr+2*i+3));
                    if(i==count/2-2)//最后一个四边形
                        addLineToLinesArray(*(vptr+2*i+2), *(vptr+2*i+3));
                }
                break;
            }
            case(GL_POLYGON):
            {
                const Vec3* vptr = &_vertexArrayPtr[first];
                for(int i=0; i<count; ++i)
                {
                    int j=(i+1)%count;
                    addLineToLinesArray(*(vptr+i), *(vptr+j));
                }
                break;
            }
            case(GL_TRIANGLE_FAN):
            {
                const Vec3* vptr = &_vertexArrayPtr[first];
                for(int i=0;i<count-1;++i)
                {
                    addLineToLinesArray(*(vptr), *(vptr+i+1));
                    if(i<count-2)
                        addLineToLinesArray(*(vptr+i+1), *(vptr+i+2));
                }
                break;
            }
            case(GL_POINTS):
                break;
            case(GL_LINES):
            {
                const Vec3* vptr = &_vertexArrayPtr[first];
                for(int i=0; i<count-1; i=i+2)
                {
                    addLineToLinesArray(*(vptr+i), *(vptr+i+1));
                }
                break;
            }
            case(GL_LINE_STRIP):
            {
                const Vec3* vptr = &_vertexArrayPtr[first];
                for(int i=0; i<count-1; ++i)
                {
                    addLineToLinesArray(*(vptr+i), *(vptr+i+1));
                }
                break;
            }
            case(GL_LINE_LOOP):
            {
                const Vec3* vptr = &_vertexArrayPtr[first];
                for(int i=0; i<count; ++i)
                {
                    int j=(i+1)%count;
                    addLineToLinesArray(*(vptr+i), *(vptr+j));
                }
                break;
            }
            default:
                // can't be converted into to lines.
                break;
        }
    }

    virtual void drawElements(GLenum mode,GLsizei count,const GLubyte* indices)
    {
        drawElementsImplementation<GLubyte>(mode, count, indices);
    }

    virtual void drawElements(GLenum mode,GLsizei count,const GLushort* indices)
    {
        drawElementsImplementation<GLushort>(mode, count, indices);
    }

    virtual void drawElements(GLenum mode,GLsizei count,const GLuint* indices)
    {
        drawElementsImplementation<GLuint>(mode, count, indices);
    }



    /** Note:
      * begin(..),vertex(..) & end() are convenience methods for adapting
      * non vertex array primitives to vertex array based primitives.
      * This is done to simplify the implementation of primitive functor
      * subclasses - users only need override drawArray and drawElements.
    */
    virtual void begin(GLenum mode)
    {
        _modeCache = mode;
        _vertexCache.clear();
    }

    virtual void vertex(const Vec2& vert) { _vertexCache.push_back(osg::Vec3(vert[0],vert[1],0.0f)); }
    virtual void vertex(const Vec3& vert) { _vertexCache.push_back(vert); }
    virtual void vertex(const Vec4& vert) { _vertexCache.push_back(osg::Vec3(vert[0],vert[1],vert[2])/vert[3]); }
    virtual void vertex(float x,float y) { _vertexCache.push_back(osg::Vec3(x,y,0.0f)); }
    virtual void vertex(float x,float y,float z) { _vertexCache.push_back(osg::Vec3(x,y,z)); }
    virtual void vertex(float x,float y,float z,float w) { _vertexCache.push_back(osg::Vec3(x,y,z)/w); }
    virtual void end()
    {
        if (!_vertexCache.empty())
        {
            setVertexArray(_vertexCache.size(),&_vertexCache.front());
            _treatVertexDataAsTemporary = true;
            drawArrays(_modeCache,0,_vertexCache.size());
        }
    }

protected:

    inline void addLineToLinesArray(const Vec3& p1, const Vec3& p2)
    {
        _linesArray->push_back(p1);
        _linesArray->push_back(p2);
    }

    template<typename TP>void drawElementsImplementation(GLenum mode,GLsizei count,const TP* indices)
    {
        if (indices==0 || count==0) return;

        typedef const TP* IndexPointer;

        switch(mode)
        {
            case(GL_TRIANGLES):
            {
                const IndexPointer ilast = &indices[count];
                for(IndexPointer  iptr=indices;iptr<ilast;iptr+=3)
                    for(int i=0; i<3; ++i)
                    {
                        int j=(i+1)%3;
                        addLineToLinesArray(_vertexArrayPtr[*(iptr+i)], _vertexArrayPtr[*(iptr+j)]);
                    }
                break;
            }
            case(GL_TRIANGLE_STRIP):
            {
                const IndexPointer iptr = indices;
                for(int i=0;i<count-1;++i)
                {
                    addLineToLinesArray(_vertexArrayPtr[*(iptr+i)], _vertexArrayPtr[*(iptr+i+1)]);
                    if(i<count-2) addLineToLinesArray(_vertexArrayPtr[*(iptr+i)], _vertexArrayPtr[*(iptr+i+2)]);
                }
                break;
            }
            case(GL_QUADS):
            {
                const IndexPointer ilast = &indices[count];
                for(IndexPointer  iptr=indices;iptr<ilast;iptr+=4)
                    for(int i=0; i<4; ++i)
                    {
                        int j=(i+1)%4;
                        addLineToLinesArray(_vertexArrayPtr[*(iptr+i)], _vertexArrayPtr[*(iptr+j)]);
                    }
                break;
            }
            case(GL_QUAD_STRIP):
            {
                const IndexPointer iptr = indices;
                for(int i=0;i<count/2-1;++i)
                {
                    addLineToLinesArray(_vertexArrayPtr[*(iptr+2*i)], _vertexArrayPtr[*(iptr+2*i+1)]);
                    addLineToLinesArray(_vertexArrayPtr[*(iptr+2*i)], _vertexArrayPtr[*(iptr+2*i+2)]);
                    addLineToLinesArray(_vertexArrayPtr[*(iptr+2*i+1)], _vertexArrayPtr[*(iptr+2*i+3)]);
                    if(i==count/2-2)//最后一个四边形
                        addLineToLinesArray(_vertexArrayPtr[*(iptr+2*i+2)], _vertexArrayPtr[*(iptr+2*i+3)]);
                }

                break;
            }
            case(GL_POLYGON):
            {
                const IndexPointer iptr = indices;
                for(int i=0; i<count; ++i)
                {
                    int j=(i+1)%count;
                    addLineToLinesArray(_vertexArrayPtr[*(iptr+i)], _vertexArrayPtr[*(iptr+j)]);
                }
                break;
            }
            case(GL_TRIANGLE_FAN):
            {
                const IndexPointer iptr = indices;
                for(int i=0;i<count-1;++i)
                {
                    addLineToLinesArray(_vertexArrayPtr[*(iptr)], _vertexArrayPtr[*(iptr+i+1)]);
                    if(i<count-2)
                        addLineToLinesArray(_vertexArrayPtr[*(iptr+i+1)], _vertexArrayPtr[*(iptr+i+2)]);
                }

                break;
            }
            case(GL_POINTS):
                break;
            case(GL_LINES):
            {
                const IndexPointer iptr = indices;
                for(int i=0; i<count-1; i=i+2)
                {
                    addLineToLinesArray(_vertexArrayPtr[*(iptr+i)], _vertexArrayPtr[*(iptr+i+1)]);
                }
                break;
            }
            case(GL_LINE_STRIP):
            {
                const IndexPointer iptr = indices;
                for(int i=0; i<count-1; ++i)
                {
                    addLineToLinesArray(_vertexArrayPtr[*(iptr+i)], _vertexArrayPtr[*(iptr+i+1)]);
                }
                break;
            }
            case(GL_LINE_LOOP):
            {
                const IndexPointer iptr = indices;
                for(int i=0; i<count; ++i)
                {
                    int j=(i+1)%count;
                    addLineToLinesArray(_vertexArrayPtr[*(iptr+i)], _vertexArrayPtr[*(iptr+j)]);
                }
                break;
            }
            default:
                // can't be converted into to lines.
                break;
        }
    }

public:
    Vec3Array *getLinesArray(){return _linesArray.release();}

protected:


    unsigned int        _vertexArraySize;
    const Vec3*         _vertexArrayPtr;

    GLenum              _modeCache;
    std::vector<Vec3>   _vertexCache;
    bool                _treatVertexDataAsTemporary;

    ref_ptr<Vec3Array> _linesArray;
};

}

#endif // LINEFUNCTOR

