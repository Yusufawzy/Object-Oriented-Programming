#include "BigDecimalInt.h"
#include<bits/stdc++.h>
using namespace std;
BigDecimalInt::BigDecimalInt(string a)
{
    if (a[0]=='-')
    {
        sign=true;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        num=a;
    }
    else if (a[0]=='+')
    {
        sign=false;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        num=a;
    }
    else
    {
        sign=false;
        a.erase(0, a.find_first_not_of('0'));
        num=a;
    }
    if (a.size()==0)
    {
        num="0";
        sign=false;
    }
    sizee = num.length();
}
BigDecimalInt::BigDecimalInt(int n)
{
    stringstream out ;
    out << n;
    string a ;
    out>>a;
    if (a[0]=='-')
    {
        sign=true;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        num=a;
    }
    else if (a[0]=='+')
    {
        sign=false;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        num=a;
    }
    else
    {
        sign=false;
        a.erase(0, a.find_first_not_of('0'));
        num=a;
    }
    if (a.size()==0)
    {
        num="0";
        sign=false;
    }
    sizee = num.length();
}
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{
    BigDecimalInt res("");
    //------------------------------------------------------------------
    int maxx = max(sizee, anotherDec.sizee);
    if (sizee > anotherDec.sizee)
    {
        int n = sizee - anotherDec.sizee;
        string a(n,'0');
        anotherDec.num =a+anotherDec.num; // if 1 + 99 then it will be 01 + 99 = 100
    }
    else if (sizee < anotherDec.sizee)
    {
        int n = anotherDec.sizee - sizee;
        string a(n,'0');
        num =a+num;
    }
    if (sign==true && anotherDec.sign==true)
    {
        //then add two numbers and add -ve sign ;
        res.num = add(num,anotherDec.num);
        res.sign=true ;
    }
    else if (sign==true && sizee > anotherDec.sizee)
    {
        res.sign=true;
        res.num=subtract(num,anotherDec.num);
        //subtract first - anotherDec
    }
    else if (sign==true && sizee <=anotherDec.sizee)
    {
        res.sign=false ;
        res.num=subtract(anotherDec.num,num);
        //subtract anotherDec - first
    }
    else if(anotherDec.sign==true && sizee > anotherDec.sizee)
    {
        res.sign=false;
        res.num=subtract(num,anotherDec.num);

        // subtract first - anotherDec
    }
    else if(anotherDec.sign==true && sizee <anotherDec.sizee)
    {
        res.sign=true;
        res.num=subtract(anotherDec.num,num);
        //subtract anotherDec - first
    }
    else if (anotherDec.sign==true && sizee ==anotherDec.sizee)
    {
        if (num>anotherDec.num)
        {
            res.sign=false;
            res.num=subtract(num,anotherDec.num);
        }
        else
        {
            res.sign=true ;
            res.num=subtract(anotherDec.num,num);
        }
    }
    else
    {
        res.sign=false;
        res.num = add(num,anotherDec.num);
        //just add the two numbers
    }
    res.sizee=res.num.size();
    sizee=num.size();
    anotherDec.sizee=anotherDec.num.size();
    return res;
    //------------------------------------------------------------------

}
int BigDecimalInt::size() const
{
    return sizee;
}
bool BigDecimalInt::checkZeros(string a)
{
    for (int i = 0, j = a.size()-1; i<=j; i++,j--)
    {

        if (a[i]!='0' || a[j]!='0')
        {
            return false;
        }
    }
    return true;
}
string BigDecimalInt::subtract(string a,string b)
{
    int ans = 0 ;
    string sum;
    int maxx = a.length();
    for (int i = maxx-1; i>=0; i--)
    {
        if (a[i] < b[i])
        {
            a[i] += 10;
            a[i - 1]--;
        }
        sum+='0' + (a[i] - '0') - (b[i] - '0');
    }

    if (sum.size()>1)
        reverse(sum.begin(),sum.end());
    if (checkZeros(sum))
    {
        return "0";
    }
    return sum;
}
string BigDecimalInt::add(string a,string b)
{

    int carry = 0, ans = 0;
    string sum;
    int maxx = a.length();
    for (int i = maxx-1; i >=0; i--)
    {
        ans = ((a[i] - '0') + (b[i] - '0') + (carry));
        if (ans > 9)
        {
            sum += ((ans % 10) + '0');
            ans /= 10;
            carry = ans;
        }
        else
        {
            carry = 0;
            sum += (ans + '0');
        }
    }
    reverse(sum.begin(),sum.end());
    if (carry != 0)
        sum= ("1")+sum;
    return sum;
}
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{
    BigDecimalInt res("");
    //------------------------------------------------------------------
    int maxx = max(sizee, anotherDec.sizee);
    if (sizee > anotherDec.sizee)
    {
        int n = sizee - anotherDec.sizee;
        string a(n,'0');
        anotherDec.num =a+anotherDec.num;
    }
    else if (sizee < anotherDec.sizee)
    {
        int n = anotherDec.sizee - sizee;
        string a(n,'0');
        num =a+num;
    }
    if (sign==true && anotherDec.sign==true)
    {
        res.num = subtract(anotherDec.num,num);
        res.sign=false ;
    }
    else if (sign==true && sizee > anotherDec.sizee)
    {
        res.sign=true;
        res.num=add(num,anotherDec.num);
    }
    else if (sign==true && sizee <=anotherDec.sizee)
    {
        res.sign=true ;
        res.num=add(anotherDec.num,num);
    }
    else if(anotherDec.sign==true )
    {
        res.sign=false;
        res.num=add(num,anotherDec.num);
    }
    else if (sizee > anotherDec.sizee)
    {
        res.sign=false;
        res.num = subtract(num,anotherDec.num);
    }
    else if(sizee<anotherDec.sizee)
    {
        res.sign=true;
        res.num=subtract(anotherDec.num,num);
    }
    else if (sizee==anotherDec.sizee)
    {
        if (num>=anotherDec.num)
        {
            res.sign=false;
            res.num=subtract(num,anotherDec.num);
        }
        else
        {
            res.sign=true ;
            res.num=subtract(anotherDec.num,num);
        }
    }
    res.sizee=res.num.size();
    sizee=num.size();
    anotherDec.sizee=anotherDec.num.size();
    return res;
}
void BigDecimalInt::operator=(BigDecimalInt anotherDec)
{
    num = anotherDec.num;
    sizee = anotherDec.sizee;
    sign = anotherDec.sign;
}

ostream& operator << (ostream&out,BigDecimalInt &b)
{
    if (b.sign)
        out<<'-';
    out<<b.num<<endl;
    return out;
}

istream& operator >> (istream&in,BigDecimalInt &b)
{
    b.num = "0";
    in >>b.num;
    return in;
}
void operator <<(BigDecimalInt &b,string a)
{
    if (a[0]=='-')
    {
        b.sign=true;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        b.num=a;
    }
    else if (a[0]=='+')
    {
        b.sign=false;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        b.num=a;
    }
    else
    {
        b.sign=false;
        a.erase(0, a.find_first_not_of('0'));
        b.num=a;
    }
    if (a.size()==0)
    {
        b.num="0";
        b.sign=false;
    }
    b.sizee = b.num.length();
}
void BigDecimalInt::operator=(string a)
{
    if (a[0]=='-')
    {
        sign=true;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        num=a;
    }
    else if (a[0]=='+')
    {
        sign=false;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        num=a;
    }
    else
    {
        sign=false;
        a.erase(0, a.find_first_not_of('0'));
        num=a;
    }
    if (a.size()==0)
    {
        num="0";
        sign=false;
    }
    sizee = num.length();
}
void BigDecimalInt::operator=(int n)
{
    stringstream out ;
    out << n;
    string a ;
    out>>a;
    if (a[0]=='-')
    {
        sign=true;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        num=a;
    }
    else if (a[0]=='+')
    {
        sign=false;
        a.erase(0,1);
        a.erase(0,a.find_first_not_of('0'));
        num=a;
    }
    else
    {
        sign=false;
        a.erase(0, a.find_first_not_of('0'));
        num=a;
    }
    if (a.size()==0)
    {
        num="0";
        sign=false;
    }
    sizee = num.length();

}
