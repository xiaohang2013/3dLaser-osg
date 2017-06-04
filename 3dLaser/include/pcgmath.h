#ifndef PCGMATH_H
#define PCGMATH_H

#include <QObject>

class pcgMath : public QObject
{
    Q_OBJECT

public:
    pcgMath();


public:
    static void init_Random(unsigned int seed = 3333){srand(seed);}
    static inline float normalizedRand(){return rand()/double(RAND_MAX);}
};

#endif // PCGMATH_H
