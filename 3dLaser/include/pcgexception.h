#ifndef PCGEXCEPTION_H
#define PCGEXCEPTION_H

#include <exception>
#include <QString>

class PCGException:public std::exception
{
public:
    PCGException(const QString& text)
        :std::exception(),excText(text){_ba=excText.toLocal8Bit();}
    ~PCGException() throw(){}
    inline const char* what() const throw(){return _ba.constData();}

protected:
    QString excText;
    QByteArray _ba;
};

class ValueErrorException:public PCGException
{
public:
    ValueErrorException(const QString& text)
        :PCGException(QString("Value Error: ")+text){}

    ~ValueErrorException() throw(){}
};

class PolygonVertexNumMismatch:public PCGException
{
public:
    PolygonVertexNumMismatch(const QString& text)
        :PCGException(QString("Polygon Vertex Num Mismatch Error: ")+text){}

    ~PolygonVertexNumMismatch() throw(){}
};

class PCGXMLParsingException:public PCGException
{
public:
        PCGXMLParsingException(const QString& text)
            :PCGException(QString("Error While parsing the XML filter plugin descriptors: ") + text){}

        ~PCGXMLParsingException() throw(){}
};

class ParsingException:public PCGException
{
public:
        ParsingException(const QString& text)
                :PCGException(QString("Parsing Error: ")+text){}

        ~ParsingException()throw(){}
};

class ValueNotFoundException:public PCGException
{
public:
        ValueNotFoundException(const QString& valName)
                :PCGException(QString("Value Name: ")+valName+QString(" has not been defined in current environment.")){}

        ~ValueNotFoundException() throw(){}
};

class NotConstException:public PCGException
{
public:
    NotConstException(const QString& exp)
        :PCGException(QString("表达式： ")+ exp + QString(" 不是常量表达式，表达式中包含有赋值运算符 \"=\".")){}

    ~NotConstException() throw(){}
};

class QueryException:public PCGException
{
public:
    QueryException(const QString& syntaxError)
        :PCGException(QString("Query Error: ")+syntaxError){}

    ~QueryException() throw(){}
};

class JavaScriptException:public PCGException
{
public:
    JavaScriptException(const QString& syntaxError)
        :PCGException(QString("JavaScript Error: ")+syntaxError){}

    ~JavaScriptException() throw(){}
};

class ExpressionHasNotThisTypeException:public PCGException
{
public:
    ExpressionHasNotThisTypeException(const QString& expectedType,const QString& exp)
        :PCGException(QString("Expression: ")+exp+" cannot be evaluated to a "+expectedType+"'s value."){}

    ~ExpressionHasNotThisTypeException() throw(){}
};

class InvalidInvariantException:public PCGException
{
public:
    InvalidInvariantException(const QString& invarianterror)
        :PCGException(QString("WARNING! Invalid Invariant: ")+invarianterror){}

    ~InvalidInvariantException() throw(){}
};

#endif // PCGEXCEPTION_H
