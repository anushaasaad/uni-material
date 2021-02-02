#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
class bank{
	int an,count=0;
	float balance,interest;
	string pin;
	public:
		void setbalance(){
			balance=1000.0;
		}
	void displaybalance(){
		cout <<"Your current balance is :" <<balance <<endl;
	}
	void deposit(){
			int d;
			cout<<"enter amount to deposit :" <<endl;
			cin>>d;
			if(d>0){
				balance+=d;
			}else{
				cout<<"amount cannot be deposited" <<endl;
			}
		}
	void interest(){
			float rate=5.0;
			int y;
			cout <<"enter no of year interest you want?:" <<endl;
			cin>>y;
			interest=(rate*y*balance)/100;
			cout <<"the interest calculated is :" <<interest <<endl;
		}
	void withdrawl(){
			int x;
			cout<< "enter amount to withdraw:" <<endl;
			cin>>x;
			if(x<balance){
				balance-=x;
			}else {
				cout <<"amount cannot be withdrawed" <<endl;
		}
		count++;
	}
	void transactions(){
			cout<<"no of transactions:" <<count <<endl;
		}
};
int main()
{
	bank b1;
	string p;
	system("cls");
	int choice;
    cout <<"1.	Display the account balance" <<endl; 
    cout <<"2.	Display the number of transactions" <<endl; 
    cout <<"3.	Display interest earned for this period" <<endl; 
    cout <<"4.	Make a deposit" <<endl; 
    cout <<"5.	Make a withdrawal" <<endl; 
    cout <<"6.	Add interest for this period" <<endl;
	cout<<"7.	Exit the program" <<endl;
    cout<<"enter your choice:" <<endl;
	cin>>choice;
	system("cls");
	while(choice!=7){
	switch(choice){
		case 1:
			cout<<"1.	Display the account balance" <<endl;
			b1.displaybalance();
			break;
		case 2:
		    cout<<"2.	Display the number of transactions" <<endl;
			b1.transactions();
			break;
		case 3:
		    cout<<"3.	Display interest earned for this period" <<endl;
		    b1.interest();
			break;
		case 4:
		    cout<<"4.	Make a deposit" <<endl;
		    b1.deposit();
		
			break;	
		case 5:
		    cout<<"5.	Make a withdrawal" <<endl;
		    b1.withdrawl();
		
			break;
		case 7:
		    cout<<"7.	Exit the program" <<endl;
			break;
		default:
			cout<<"error" <<endl;
			break;
			
	}

}
}
