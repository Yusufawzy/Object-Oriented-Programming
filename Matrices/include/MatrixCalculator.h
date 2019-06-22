#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

#include "Matrix.h"
using namespace std;
class MatrixCalculator
{
    public:
        MatrixCalculator();
        void start();
        bool checkA_S(int r1,int c1,int r2,int c2);
        bool checkM(int r1,int c1,int r2,int c2);
};

#endif // MATRIXCALCULATOR_H
