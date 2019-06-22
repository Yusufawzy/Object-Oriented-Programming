
#include "Matrix.h"
using namespace std;

template <class T>
Matrix<T>::Matrix(int r, int c) {
    rows = r; cols = c;
    arr = new T *[r];
    for (int i = 0; i < r; i++) {
        arr[i] = new T[c];
    }
    for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j]=0;
            }
        }
}
template <class T2>
ostream &operator<<(ostream &out, const Matrix<T2> &obj) {
    for (int i = 0; i < obj.rows; i++){
        for (int j = 0; j < obj.cols; j++) {
            out << obj.arr[i][j] << " ";
        }
        out<<endl;
    }
    return  out;
}
template <class T2>
istream& operator>>(istream& in,Matrix<T2> &obj) {
    for (int i = 0; i < obj.rows; i++) {
        for (int j = 0; j < obj.cols; j++) {
            in >> obj.arr[i][j];
        }
    }
    return in;
}

template <class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete [] arr[i];
    }
    delete[] arr;
}
template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &another){
    if (rows!=another.rows || cols!=another.cols){cout<<"Can't make the Addition"<<endl;}
    else {
        Matrix res (rows,cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.arr[i][j]=arr[i][j]+another.arr[i][j];
            }
        }
        return  res;
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix& obj) {
    rows = obj.rows;
    cols = obj.cols;

    arr = new T*[rows];
    for ( int i = 0; i < rows; i++) {
        arr[i] = new T[cols];
        for ( int j = 0; j < cols; j++) {
            arr[i][j] = obj.arr[i][j];
        }
    }
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& obj) {
    for ( int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
// we deleted the old ones so we made our new matrix and initialize it as we want
    rows=obj.rows;
    cols=obj.cols;

    arr = new T*[rows];
    for ( int i = 0; i < rows; i++) {
        arr[i] = new T[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = obj.arr[i][j];
        }
    }
}
template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &another){
    if (rows!=another.rows || cols!=another.cols){cout<<"can't make the Subtraction"<<endl;}
    else {
        Matrix res (rows,cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.arr[i][j]=arr[i][j]-another.arr[i][j];
            }
        }
        return  res;
    }
}
template <class T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix tran(cols,rows);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
        {
            tran.arr[j][i]=arr[i][j];
        }
    return tran;
}

template  <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &another){
    if(rows!=another.cols){cout<<"can't make the Multiplication"<<endl;Matrix mat(0,0);return mat;}// NEED to be handled
    else{
        Matrix  res (rows,another.cols);
        for(int i = 0; i < cols; i++){
            for(int j = 0; j < cols; j++)
            {
                res.arr[i][j]=0;
            }}
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < another.cols; ++j)
                for(int k = 0; k < cols; ++k)
                {
                    res.arr[i][j] += arr[i][k] * another.arr[k][j];
                }
        return  res;
    }
}
