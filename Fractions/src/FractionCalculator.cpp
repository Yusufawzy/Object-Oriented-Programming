#include "FractionCalculator.h"
#include <iostream>
#include <Fraction.h>
void FractionCalculator::Start()
{
    Fraction a,b,c;
    int x;
    while(1)
    {
        cout<<"1- Input the two numbers\n2- Subtraction\n"
            <<"3- Addition\n4- Multiplication\n5- Division\n"
            <<"6- Fraction1 >  Fraction2 \n7- Fraction1 >= Fraction2 \n"
            <<"8- Fraction1 <  Fraction2\n"
            <<"9- Fraction1 <= Fraction2\n10-Fraction1 == Fraction2 \n"
            <<"11- Quit\n" ;
        cin>>x;
        if (x==1)
        {
            cout<<"Enter the First number in this Form (a/b) \n";
            cin>>a;
            cout<<"Enter the Second number in this Form (a/b)\n";
            cin>>b;
        }
        else if (x==2)
        {
            c=a-b;
            cout<<"Result after Subtraction is "<<c<<endl;
        }
        else if(x==3)
        {
            c=a+b;
            cout<<"Result after Addition is "<<c<<endl;;
        }
        else if(x==4)
        {
            c=a*b;
            cout<<"Result after Multiplication is "<<c<<endl;
        }
        else if(x==5)
        {
            c=a/b;
            cout<<"Result after Division is "<<c<<endl;
        }
        else if(x==6)
        {
            bool flag=a>b;
            cout<<"the result of a>b is ";
            if (flag)cout<<"TRUE\n";
            else cout<<"FALSE\n";
        }
        else if(x==7)
        {
            bool flag = (a>=b);
            cout<<"the result of a>=b is ";
            if (flag)cout<<"TRUE\n";
            else cout<<"FALSE\n";
        }
        else if(x==8)
        {
            bool flag = a<b;
            cout<<"the result of a<b is ";
            if (flag)cout<<"TRUE\n";
            else cout<<"FALSE\n";
        }
        else if(x==9)
        {
            bool flag = (a<=b);
            cout<<"the result of a<=b is ";
            if (flag)cout<<"TRUE\n";
            else cout<<"FALSE\n";
        }
        else if(x==10)
        {
            bool flag = (a==b);
            cout<<"the result of a=b is ";
            if (flag)cout<<"TRUE\n";
            else cout<<"FALSE\n";
        }
        else if(x==11)
        {
            break;
        }
    }
    return ;

}
