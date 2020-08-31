#include <iostream>

using namespace std;

class employee{
	char name;
	int age;
	public:
		char getname(){
			return name;
		}
		void setname(char n){
		    name=n;
		   	cout<<"name:" <<name <<endl;
		}
		employee()
		{
			name=" ";
		}
		employee(int a){
			age=a;
		}
	
};
int main()
{
	employee e1;
	e1.setname("ali");
	employee e2;
	e2.setname("ahmed");
}
