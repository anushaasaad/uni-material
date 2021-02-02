#ifndef Q3_H
#define Q3_H
#include<string>
using namespace std;

class Car{
    string model, colour;
    int price, year;
    public:
    Car();
    Car(string model,string colour, int price, int year);
    ~Car();
    Car (const Car& obj);
    void operator=(const Car& obj);
    void Display();
};
#endif