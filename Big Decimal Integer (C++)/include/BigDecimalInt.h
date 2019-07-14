#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include<bits/stdc++.h>
using namespace std;
class BigDecimalInt
{
private :
    string num;
    int sizee;
    bool sign ;
public:
    BigDecimalInt(string a);
    BigDecimalInt(int n) ;
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    int size() const;
    string subtract(string a,string b);
    string add(string a,string b);
    BigDecimalInt operator-(BigDecimalInt anotherDec);
    friend ostream &operator<<(ostream &out, BigDecimalInt& b);
    friend istream &operator>>(istream &in, BigDecimalInt& b);
    void operator=(BigDecimalInt anotherDec);
    void operator=(string a);
    void operator=(int n);
    friend void operator <<(BigDecimalInt &b,string a);
    bool checkZeros(string a);
};


#endif // BIGDECIMALINT_H
