#include "Fraction.h"

Fraction::Fraction()
{
    x=0,y=0;
}
Fraction::Fraction (string a)
{
    x=0,y=0;
}
int Fraction::gcd(int a, int b)
{
   if (b==0)return a;
   return gcd(b,a%b);
   }
bool Fraction::reduction()
{
    if (y==0)
    {
        cout<<"can't divide by 0"<<endl;
        x=0;
        y=0;
        return false;
    }
    if (x==0)
    {
        x=0;
        y=1;
        return false;
    }
    int g =gcd(x,y);
    if (g!=0)
    {
        x/=g;
        y/=g;
    }
    return true;
}
Fraction Fraction::operator* (Fraction anotherDec)
{
    Fraction res;
    res.y=y*anotherDec.y;
    res.x=x*anotherDec.x;
    int g =gcd(res.x,res.y);
    if (g!=0)
    {
        res.x/=g;
        res.y/=g;
    }
    return res ;
}
Fraction Fraction::operator/ (Fraction anotherDec)
{
    if (anotherDec.x==0)
    {
        cout<<"Can't divide by Zero\n";
        anotherDec.x=0;
        anotherDec.y=0;
        return anotherDec;
    }
    else
    {
        Fraction res;
        res.y=y*anotherDec.x;
        res.x=x*anotherDec.y;
        int g =gcd(res.x,res.y);
        if (g!=0&&(res.y%g==0)&&(res.x%g==0))
        {
            res.x/=g;
            res.y/=g;
        }
        return res ;
    }
}
Fraction Fraction::operator+ (Fraction anotherDec)
{
    Fraction res;
    if (y==anotherDec.y)
    {
        res.x=x+anotherDec.x;
        res.y=y;
    }
    else
    {
        res.x = x*anotherDec.y + anotherDec.x*y ;
        res.y = y*anotherDec.y;
    }
    int g =gcd(res.x,res.y);
    if (g!=0&&(res.y%g==0)&&(res.x%g==0))
    {
        res.x/=g;
        res.y/=g;
    }
    return res ;

}
Fraction Fraction::operator- (Fraction anotherDec)
{
    Fraction res;
    if (y==anotherDec.y)
    {
        res.x=x-anotherDec.x;
        res.y=y;
    }
    else
    {
        res.x = x*anotherDec.y - anotherDec.x*y ;
        res.y = y*anotherDec.y;
    }
    int g =gcd(res.x,res.y);
    if (g!=0&&(res.y%g==0)&&(res.x%g==0))
    {
        res.x/=g;
        res.y/=g;
    }
    return res ;
}
bool operator==(Fraction a,Fraction b)
{
    float x1=a.x,y1=a.y,x2=b.x,y2=b.y;
    return ((x1/y1)==(x2/y2));
}
bool operator<(Fraction a,Fraction b)
{
    float x1=a.x,y1=a.y,x2=b.x,y2=b.y;
    return ((x1/y1)<(x2/y2));
}
bool operator>(Fraction a,Fraction b)
{
    float x1=a.x,y1=a.y,x2=b.x,y2=b.y;
    return ((x1/y1)>(x2/y2));
}
bool operator>=(Fraction a,Fraction b)
{
    float x1=a.x,y1=a.y,x2=b.x,y2=b.y;
    return ((x1/y1)>=(x2/y2));
}
bool operator<=(Fraction a,Fraction b)
{
    float x1=a.x,y1=a.y,x2=b.x,y2=b.y;
    return ((x1/y1)<=(x2/y2));
}
ostream& operator << (ostream&out,Fraction& b)
{
    if (b.y==1)
    {
        out<<b.x<<endl;
        return out;
    }
    if (b.y<0 && b.x<0)
    {
        b.y=abs(b.y);
        b.x=abs(b.x);
    }
    else if(b.y<0)
    {
        b.y*=-1;
        b.x*=-1;
    }
    out<<b.x<<"/"<<b.y<<endl;
    return out;
}
istream& operator >> (istream&in,Fraction& b)
{
    char c;
    in>>b.x>>c>>b.y;
    b.reduction();
    return in;
}
