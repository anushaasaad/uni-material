#include <iostream>
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
		   int temp=top;
		    top--;
		    return a[temp];
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
				}
				else
				{
					return false;
				}
		}
		void reverse(stack &obj)
			{
				int temp=top;
				for(int i=0;i<=temp;i++)
				{
					
					obj.push(this->pop());
				}
			}
	    void display()
			{
				for(int i=0;i<=top;i++)
				{
					cout<<a[i]<<" ";
				}
			}
};
int main(){
	int a[10],d;
	int n;
	stack s,s1;
	cout<<"Enter Array Size :"<<endl;
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
	s.reverse(s1);
	cout<<endl<<"AFTER REVERSE :"<<endl;
	s1.display();
	cout<<endl<<"BY POP : "<<endl<<s.pop();
	cout<<endl<<"BY PEEK : "<<endl<<s.peek();
	return 0;
}
