#include <iostream>
#include <queue>
using namespace std;
class stack{
	int size=0;
	queue<int> q1,q2;
	public:
		void push(int d){
			q1.push(d);
			size++;
		}
		void pop(){
			if(q1.empty()){
				cout<<"stack is empty" <<endl;	
			}
			while(size!=1){
				q2.push(q1.front());
				q1.pop();
				size--;
			}
			cout<<q1.front() <<endl;
			q1.pop();
			size--;
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
				size++;
			}
		}
};
int main()
{
	stack s1;
	s1.push(2);
	s1.push(22);
	s1.push(21);
	s1.push(1);
	s1.push(12);
	s1.push(5);
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
}
