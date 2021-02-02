#include <iostream>
using namespace std;
class bank{
	string name;
	int an;
	float balance;
	public:
		void setbalance(float bal){
			balance=bal;
		}
		void setdetails(string n, int accno){
			name=n;
			an=accno;
		}
		void getdetails(){
			cout<<"name: " <<name <<endl;
			cout<<"balance:" <<balance <<endl;
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
	    void showdata(){
	    	cout<<"NAME: " <<name <<endl;
	    	cout<<"Current balance:" <<balance <<endl;
		}
	
};
int main()
{
	bank b1;
	int accno,choice;
	string n;
	float bal;
	cout<<"enter your balance:" <<endl;
	cin>>bal;
	cout<<"enter your name:" <<endl;
	cin>>n;
	cout<<"enter your account number:" <<endl;
	cin>>accno;
	b1.setdetails(n,accno);
	b1.setbalance(bal);
	cout<<"enter your choice:" <<endl;
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"withdrawl" <<endl;
			b1.withdrawl();
			cout<<"enter your choice:" <<endl;
        	cin>>choice;
				
			break;
		case 2:
		    cout<<"deposit" <<endl;
			b1.deposit();
			
			break;
		case 3:
		    cout<<"show data" <<endl;
			b1.showdata();
			break;	
		default:
			cout<<"error" <<endl;
			break;
			
	}
}
