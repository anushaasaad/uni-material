#include "Q3.h"
#include <iostream>
#include <string>

using namespace std;
Car::Car(){}
Car::Car(string model,string colour, int price, int year){
    this->model=model;
    this->colour=colour;
    this->price=price;
    this->year=year;
}
Car::Car(const Car& obj){
    cout<<"Copy Constructor." <<endl;
    model=obj.model;
    colour=obj.colour;
    price=obj.price;
    year=obj.year;
}
void Car::operator=(const Car& obj){
    cout<<"Assignment Operator called." <<endl;
    model=obj.model;
    colour=obj.colour;
    price=obj.price;
    year=obj.year;
}
Car:: ~Car(){
    cout<<"constructor destroyed." <<endl;
}
void Car::Display(){
    cout<<"Model : "<<model <<endl;
    cout<<"Color : "<<colour <<endl;
    cout<<"Year : "<<year <<endl;
    cout<<"Price : "<<price <<endl;
}
