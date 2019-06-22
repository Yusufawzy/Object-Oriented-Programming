#include <bits/stdc++.h>
using namespace std;
#ifndef P3_MATRIX_H
#define P3_MATRIX_H

template <class T>
class Matrix {
private :
    int rows, cols;
    T **arr ;
public:
    Matrix(int r, int c) ;
    ~Matrix() ;
    Matrix<T>& operator=(const Matrix&);
    Matrix(const Matrix& );
    template <class T2>
    friend ostream& operator<<(ostream &out,const Matrix<T2> &obj) ;
    template <class T2>
    friend istream& operator>>(istream& in, Matrix<T2>& obj) ;
    Matrix<T> operator+(Matrix<T> &another);
    Matrix<T> operator-(Matrix<T> &another);
    Matrix<T> transpose() const;
    Matrix<T> operator*(Matrix<T> &another);
};

#endif //P3_MATRIX_H
