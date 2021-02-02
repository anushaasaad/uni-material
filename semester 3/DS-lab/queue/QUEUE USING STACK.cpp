#include <iostream>
#include<stack>
using namespace std;
class queue{
	public:
		stack<int> s1,s2;
		void enqueue(int d){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(d);
			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}
			
		}
		int dequeue(){
			if(s1.empty()){
				cout<<"queue is empty. " <<endl;
			}else{
				int pop=s1.top();
				s1.pop();
				return pop;
			}
	}
	
};
int main()
{
	queue q;
	q.enqueue(11);
	q.enqueue(2);
	q.enqueue(10);
	cout<<"poped value: " <<q.dequeue() <<endl;
	cout<<"poped value: " <<q.dequeue() <<endl;
	cout<<"poped value: " <<q.dequeue() <<endl;
}
