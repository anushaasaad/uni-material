#include "Q1.h"
#include <iostream>
#include <cmath>

using namespace std;

QuadraticEquation::QuadraticEquation()
{
    cout<<"Enter the value of a, b, and c: ";
    cin>>a>>b>>c;
}

void QuadraticEquation::Calculation()
{
    D=(b*b)-(4*a*c);
    if(D==0)
    {
        x1=(-b+sqrt(D))/(2*a);
        cout<<"x1 = "<<x1<<"\t x2 = "<<x1 <<endl;
        cout<<"Roots are real and equal"  <<endl;
    }
    else if(D>0)
    {
        x1=(-b+sqrt(D))/(2*a);
        x2=(-b-sqrt(D))/(2*a);
        cout<<"x1 = "<<x1<<"\t x2 = "<<x2 <<endl;
        cout<<"Roots are real and distinct" <<endl;
    }
    else if(D<0)
    {
        m=-b/(2*a);
        n=sqrt(-D)/(2*a);
        cout<<"x1 = " <<m << "+" <<n <<"i"<<"\t x2 = "<<m<<"-"<<n<<"i" <<endl;
        cout<<"Roots are complex and distinct" <<endl;
    }
}