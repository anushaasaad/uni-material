#include<iostream>
#define size 100
using namespace std;
class queue{
	int rear, front;
	int n;
	public:
		int a[size];
		queue(int n){
			rear=-1;
			front=-1;
			this->n=n;
		}
		bool isempty(){
			if(rear==-1){
				return true;
			}else{
				return false;
			}
		}
		bool isfull(){
			if(front==0 && rear==n-1){
				return true ;
			}else{
				return false;
				
			}
		}
		void enqueue(int data){
			if(!isfull()){
				if(front==-1){
					front=0;
				}
					rear++;
					a[rear]=data;
				}
			
			}
		int dequeue(){
			if(isempty()){
				cout<<"queue is empty";
			}else{
				int value= a[front];
				if(front>=rear){
				front = -1;
				rear = -1;
			 }else{
				front++;
				return(value);
			}
		}
	}
		int frontt(){
			return a[front];
		}
		int last(){
			return a[rear];
		}
		void display(){
			if(isempty()){
				cout<<"queue is empty" <<endl;
			}else{
				for(int i=front; i<=rear; i++){
					cout << a[i] << "\t";
			 }
		}
	}
	
};
struct node{
	int data;
	node *next;
};
class ll_queue{
	node *head, *tail;
	public:
	ll_queue(){
		head=NULL;
		tail=NULL;
	}	
	bool isempty(){
		if(head==NULL && tail==NULL){
			return true;
		}else{
			return false;
		}
	}
	void enqueue(int d){
			node *temp=new node;
			temp->data=d;
			temp->next=NULL;
			if(isempty()==true){
				head=temp;
				tail=temp;
			}else{
				tail->next=temp;
				tail=temp;
				tail->next=NULL;
			}
	}
	void dequeue(){
		head=head->next;
	}
	void display(){
		node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};
int main()
{
	queue q(5);
	ll_queue l;
	int x;
	cout<<"enter any five numbers for Queue: "<<endl;
	for(int i=0; i<5; i++){
		cin>>x;
		q.enqueue(x);
		l.enqueue(x);
	}
	cout<<"queue implementation through array:" <<endl;
	q.display();
	cout<<endl<<"queue implementation through linkedlist:" <<endl;
	l.display();
}
