#include "Q3.cpp"
#include<iostream>
#include<string>
using namespace std;

int main(){
    int y, p;
    string m,c;
    cout<<"Enter model of the Car:" <<endl;
    cin>>m;
    cout<<"Enter year of the Car:" <<endl;
    cin>>y;
    cout<<"Enter price of the Car:" <<endl;
    cin>>p;
    cout<<"Enter colour of the Car:" <<endl;
    cin>>c;
    cout<<"CAR 1" <<endl;
    Car c1(m,c,p,y);
    c1.Display();
    cout<<"CAR 2" <<endl;
    Car c2(c1);
    c2.Display();
    cout<<"CAR 3" <<endl;
    Car c3(c1);
    c3.Display();
}