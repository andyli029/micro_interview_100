#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
bool equal(double num1,double num2){
    if( abs(num1 - num2) < 0.0000001 )
        return true;
    else
        return false;
}
 
double PowerWithUnsignedExponent(double base,unsigned int absExponent){
    if(absExponent == 0)
        return 1;

    if(absExponent == 1)
        return base;
 
    double result = PowerWithUnsignedExponent(base, absExponent>>1);
    result = result * result;

    if((absExponent & 0x1) == 1)
        result = result * base;
 
    return result;
}
 
double Power(double base,int exponent){
    unsigned int absExponent = (unsigned int)exponent;
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
    double result = PowerWithUnsignedExponent(base, absExponent);
 
    if(exponent < 0)
        result= 1.0 / result;

    return result;
}
 
int main()
{
    cout<<Power(2, -3)<<endl;
    cout<<Power(0, -1)<<endl;
    cout<<Power(5, 0)<<endl;

    return 0;
}