#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class movie
{
	string name;
	double child,adult;
	int ctick,adtick,net;
	float per,gross,amount;
	
	public:
	movie(string name, double child,double adult, int ctick, int adtick, float per){
		this->name=name;
		this->child=child;
		this->adult=adult;
		this->ctick=ctick;
		this->adtick=adtick;
		this->per;
	}
	void netsale(){
		gross=(ctick*child+adtick+adult);
		amount=(gross*per)/100;
		net = gross-amount;
	}
	void printdetails(){
		cout<<"____________________________________________________________________________"<<endl;
		cout<<" movie name                                        :" <<name <<endl;
    	cout<<"number of tickets sold                             :" <<(adtick+ctick) <<endl;
    	cout<<"percentage of gross amount tobe donated to charity.:"<<per <<endl;
    	cout<<"Gross Amount                                       : " <<gross <<endl;
    	cout<<"Amount Donated                                     : "<<amount <<endl;
    	cout<<"net sale                                           :" <<net <<endl;
	}
};
    
int main()
{
	string n;
	double c,ad;
	float p;
	int ct,adt;
	cout<<"enter movie name:" <<endl;
	cin>>n;
	cout<<"enter adult ticket price:" <<endl;
	cin>>ad;
	cout <<"enter child ticket price:" <<endl;
	cin>>c;
	cout <<"enter number of adult tickets sold:" <<endl;
	cin>>adt;
	cout <<"enter number of child tickets sold:" <<endl;
	cin>>ct;
	cout <<"enter percentage of the gross amount to be donated to the charity.:" <<endl;
    cin>>p;
    movie m1(n,c,ad,ct,adt,p);
    m1.netsale();
    system("cls");
    m1.printdetails();
    
}

