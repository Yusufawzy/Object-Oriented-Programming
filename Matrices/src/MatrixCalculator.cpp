#include "MatrixCalculator.h"
#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

MatrixCalculator::MatrixCalculator()
{
}
bool MatrixCalculator::checkA_S(int r1,int c1,int r2,int c2)
{
    return (r1==r2&&c1==c2);
}
bool MatrixCalculator::checkM(int r1,int c1,int r2,int c2)
{
    return (r1==c2);
}

void MatrixCalculator::start()
{
        while(true)
    {
        cout<<"Welcome to (Joe) Matrix Calculator\n----------------------------------------\n";
        cout<<"1- Perform Matrix Addition\n2- Perform Matrix Subtraction\n";
        cout<<"3- Perform Matrix Multiplication\n4- Matrix Transpose\n";
        cout<<"5- To End\n";
        cout<<"Please Enter your Operation Number\n";
        int n;
        cin>>n;
        cout<<"Please Enter your Dimensions of the first Matrix Separated by a space\n" ;
        int r1,c1;
        cin>>c1>>r1;
        Matrix<int> m1(r1,c1);
        cout<<"Fill the Matrix\n";
        cin>>m1;
        cout<<"Please Enter your Dimensions of the Second Matrix Separated by a space\n" ;
        int r2,c2;
        cin>>c2>>r2;
        Matrix<int> m2(r2,c2);
        cout<<"Fill the Matrix\n";
        cin>>m2;
        if(n==1)
        {
            cout<<"The Resulted Matrix after Addition\n";
            if (checkA_S(r1,c1,r2,c2))
            {
                Matrix<int> res(r1,c1);
                res = m1+m2;
                cout<<res<<endl;
            }
            else
            {
                cout<<"Can't perform Addition\n";
            }

        }
        else if (n==2)
        {

            if (checkA_S(r1,c1,r2,c2))
            {
                cout<<"The Resulted Matrix after Subtraction\n";
                Matrix<int> res(r1,c1);
                res = m1-m2;
                cout<<res<<endl;
            }
            else
            {
                cout<<"Can't perform Subtraction\n";
            }

        }
        else if (n==3)
        {
            if (checkM(r1,c1,r2,c2))
            {
                cout<<"The Resulted Matrix after Multiplication\n";
                Matrix<int> res(r1,c2);
                res = m1*m2;
                cout<<res<<endl;
            }
            else
            {
                cout<<"Can't perform Multiplication\n";
            }
        }
        else if(n==4)
        {
            cout<<"Which Matrix you want to Transpose 1 or 2\n";
            int x ;
            cin>>x;
            if (x==1)
            {
                Matrix<int> res(c1,r1);
                res = m1.transpose();
                cout<<res<<endl;
            }
            else if (x==2)
            {
                Matrix<int> res(c2,r2);
                res = m2.transpose();
                cout<<res<<endl;
            }
            else
            {"invalid input\n";
            }
        }
        else if (n==5)
        {
            return;
        }
        else
        {
            cout<<"You have entered an invalid input\n";
            continue;
        }

    }
}
