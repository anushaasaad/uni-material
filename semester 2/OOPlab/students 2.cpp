#include <iostream>
#include <string>
using namespace std;
class student{
	string name;
	int rollno,total=0;
	int *marks;
	float per;
	public:
    student(string n,int r, int *m){
        name=n;
        rollno=r;
        marks = m;
    }
    void getdetails(){
        cout<<"name:" <<name <<endl;
        cout <<"roll no:" <<rollno <<endl;
        for(int i=0; i<4; i++){
            cout<<"marks of subject " <<i+1 <<"is: ";
			cout << *(marks+i) << endl;
        }
        cout<<"total:" <<total <<endl;
        cout<<"percentage: " <<per <<endl;
    }
    void percentage(){
    	for(int i=0; i<4; i++){
		total=total+(*(marks+i));
        }
    	per=(total*100)/400;
	}
};
int main(){
	string n;
	int r,m[4];
	cout <<"enter student name:" <<endl;
	cin>>n;
	cout<<"enter student rollno:" <<endl;
	cin>>r;
	for(int i=0; i<4; i++){
		cout<<"enter marks of " <<i+1 <<" subject out of 100: "<<endl;
		cin>>m[i];
	}
	student s1(n,r, m);
	s1.percentage();
	s1.getdetails();
}
