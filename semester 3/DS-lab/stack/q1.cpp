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
		void primefactors(int data){
		for(int i=2; i<=data; i++)
	    {
	        if(data%i==0)
	        {
	            int flag = 1;
	            for(int j=2; j<=i/2; j++)
	            {
	                if(i%j==0)
	                {
	                    flag = 0;
	                    break;
	                }
	            }
	            if(flag==1)
	            {
	                push(i); 
	            }
	        }
	    }
	}
		
};
int main(){
	int a[10],d;
	int n;
	stack s,s1;
//	cout<<"Enter Array Size :"<<endl;
//	cin>>n;
//	for(int i=0; i<n; i++){
//		if(s.isfull()==true){
//		cout<<"stack is full" <<endl;
//		break;
//	}else{
//		cin>>a[i];
//		s.push(a[i]);
//		}
//	}
	s.primefactors(30);
	while(!s.isempty()){
		cout<<s.pop() <<endl;
	}
	return 0;
}
	
