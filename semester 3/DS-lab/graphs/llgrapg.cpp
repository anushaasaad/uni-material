#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

class linkedlist{
	node *head , *tail;
	public:
		linkedlist(){
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
	int v;
	cout<<"enter number of vertices" <<endl;
	cin>>v;
	linkedlist l[v];
	linkedlist a;
	int e1, e2;
	for(int i=0; i<v; i++){
			cout<<"enter first node for the edge: " <<endl;
			cin>>e1;
			cout<<"enter second node for the edge: " <<endl;
			cin>>e2;
		//	a.add(e1,e2,l);
		}
}


