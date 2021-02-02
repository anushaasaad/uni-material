#include<iostream>
using namespace std;
class stack{
	int a[10];
	int n=10;
	int top=-1;
	public:
		void push(int data){
			top++;
			a[top]=data;
		}
		int pop(){
			if(top<0){
				return 0;
			}else{
				return a[top--];
		}
	}
		int peek(){
			return a[top];
		}
		bool isfull(){
			if(top==n-1){
				return true;
			}else{
				return false;
			}
		}
		bool isempty(){
			if(top<0)
				{
					return true;
			}else{
				return false;
			}
		}
 //friend bool operator==(stack& ,stack& );
 	bool operator==(stack& obj1){
     int flag=0;
     if(obj1.isempty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        while (!obj1.isempty())
        {    
            if(obj1.pop()==pop())
            {
                flag=1;
            }
            else
            {
                return false;
                break;
            }
            }
 		if (flag==1)
            {
                return true;
            }     
    }
 }
};
int main(){
	int a[10],d;
	int n;
	stack s,s1;
	cout<<"Enter Array Size for stack 1"<<":"<<endl;
	cin>>n;
	for(int i=0; i<n; i++){
		if(s.isfull()==true){
		cout<<"stack is full" <<endl;
		break;
	}else{
		cin>>a[i];
		s.push(a[i]);
		}
	}
	cout<<"Enter Array Size for stack 2"<<":"<<endl;
	cin>>n;
	for(int i=0; i<n; i++){
		if(s1.isfull()==true){
		cout<<"stack is full" <<endl;
		break;
	}else{
		cin>>a[i];
		s1.push(a[i]);
		}
	}
	if(s==s1){
		cout<<"EQUAL";
	}else{
		cout<<"NOT-EQUAL";
	}

}
	
