#include <bits/stdc++.h>
#include "BigDecimalInt.h"
using namespace std;

int main()
{
// Constructor takes string as a parameter
    /* BigDecimalInt num1("11");
     BigDecimalInt num2("-111111");
     BigDecimalInt num3 = num2+num1;
     cout << "num1 = " << num1 << endl;
     cout << "num2 = " << num2 << endl;
     cout << "num2 + num1 = " << num3 << endl;
    // overloading output operator also for reassign the number ;
     num1<<"-30";
     num2<<"-30";
     num3 = num2 - num1 ;
     cout << "num1 = " << num1 << endl;
     cout << "num2 = " << num2 << endl;
     cout << "num2 - num1 = " << num3 << endl;
     num1=120;
     num2="88888888888888";
     num3 = num2 - num1 ;
     cout << "num1 = " << num1 << endl;
     cout << "num2 = " << num2 << endl;
     cout << "num2 - num1 = " << num3 << endl;
     num3= num1 - num2;
     cout << "num1 - num2 = " << num3 << endl;
     num1<<"235423534634069545";
     num2<<"3453245645645632521534532465";
     num3 = num2 - num1 ;
     cout << "num1 = " << num1 << endl;
     cout << "num2 = " << num2 << endl;
     cout << "num2 - num1 = " << num3 << endl;
     num1<<"-1000000000000000000000000000";
     num2<<"1";
     num3 = num2 + num1 ;
     cout << "num1 = " << num1 << endl;
     cout << "num2 = " << num2 << endl;
     cout << "num2 + num1 = " << num3 << endl; */
    int n ;
    BigDecimalInt num1(0),num2(0);
    string a ,b;
    while(true)
    {
        cout<<"First Number:";
        cin>>a;
        cout<<"Second Number:";
        cin>>b;
        cout<<"Choose One Operation\n";
        num1 = a , num2  = b;
        cout<<"1- Add\n2- Subtract\n";
        cin>>n;
        if (n==1)
        {
            BigDecimalInt num3 = num1  + num2;
            cout<<num3;
        }
        else if (n==2)
        {
            BigDecimalInt num3 = num1  - num2;
            cout<<num3;
        }
        cout<<"==============================\n";
    }
    return 0;
}
