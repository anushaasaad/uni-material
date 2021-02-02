#include <iostream>
#define size 100
using namespace std;
class stack{
	int top;
	int n;
	public:
		int a[size];
		stack(int n){
		this->top=-1;	
		this->n=n;
		}
		bool empty(){
			if(top==-1){
				return true;
			}else{
				return false;
			}
		}
		bool full(){
			if(top==n)
			{
				return true;
			}else{
				return false;
			}
		}
		int topp(){
			return a[top];
		}
		void pop(){
			top--;
		}
		void push(int d){
			if(full()){
				cout<<"stack is full" <<endl;
			}else{
				top++;
				a[top]=d;
			}
		}
		void display(){
			while(!empty()){
				cout<<topp() <<" ";
				pop();
			}
		}
};
struct node{
	int data;
	node *next;
};
class ll_stack{
	node *head , *tail;
	public:
		ll_stack(){
			head=NULL;
			tail=NULL;
		}
		bool empty(){
			if(head==NULL && tail==NULL){
				return true;
			}else{
				return false;
			}
		}
		int topp(){
			return head->data;
		}
		void pop(){
			head=head->next;
		}
		void push(int d){
			node *temp=new node;
			temp->data=d;
			temp->next=NULL;
			if(empty()){
				head=tail=temp;
			}else{
				tail->next=temp;
				temp->next=NULL;
				tail=temp;
			}
		}
		void display(){
			node *temp=head;
			while(temp!=NULL){
				cout<<temp->data <<" ";
				temp=temp->next;
			}
		}
};
int main(){
	stack s(5);
	ll_stack l;
	int x;
	cout<<"enter any five numbers for stack: "<<endl;
	for(int i=0; i<5; i++){
		cin>>x;
		s.push(x);
		l.push(x+1);
	}
	cout<<"Stack implementation through array: "<<endl;
	s.display();
	cout<<endl<<"Stack implementation through linkedlist: "<<endl;
	l.display();
}
