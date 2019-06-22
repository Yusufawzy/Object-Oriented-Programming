#include<bits/stdc++.h>
using namespace std;
#ifndef FRACTION_H
#define FRACTION_H

class Fraction{
public :
    int x,y ;
public:
    Fraction();
    Fraction (string a);
    int gcd(int a, int b) ;
    bool reduction();
    Fraction operator* (Fraction anotherDec);
    Fraction operator/ (Fraction anotherDec);
    Fraction operator+ (Fraction anotherDec);
    Fraction operator- (Fraction anotherDec);
    friend  bool operator==(Fraction a ,Fraction b);
    friend  bool operator<(Fraction a ,Fraction b);
    friend  bool operator>(Fraction a ,Fraction b);
    friend  bool operator>=(Fraction a ,Fraction b);
    friend  bool operator<=(Fraction a ,Fraction b);
    friend ostream& operator << (ostream&out,Fraction& b);
    friend istream& operator >> (istream&in,Fraction& b);
};

#endif // FRACTION_H
