#include<iostream>
using namespace std;
class node {
	public:
	int data;
	node *next;
	node *prev;
	public:
		node *head, *tail;
		node(){
			data=0;
			head=NULL;
			tail=NULL;
		}
		node(int d){
			data = d;
			next=NULL;
			prev=NULL;
		}
		node(int d, node* p, node* n){
			data=d;
			prev=p;
			next=n;
		}
};
class linkedlist{
	public:
	node *head, *tail;
	public:
		linkedlist(){
			head=NULL;
			tail=NULL;
		}
		void add_node(int n){
		//node *tmp = new node(n);
		if(head == NULL)
		{
			head=tail= new node(n);
		}else{
			tail= new node(n,tail,NULL);
			tail->prev->next=tail;
			}
}
		void display(){
			node *temp= new node;
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		void insert_at_head(int d){
			//head=new node(d);
			if(head==NULL){
				head=tail=new node(d);
			}else{
				head=new node(d,NULL,head);
				//temp->next=head;
				head->next->prev=head;
			}
			
		}
		void insertion_after_given_node(int n ,int d){
			if(head==NULL){
				head=tail=new node(d,NULL, NULL);
			}else{
				node *tmp=new node, *ptr;
 				for(tmp=head; tmp!=NULL; tmp=tmp->next){
 					if(tmp->data==n){
 						ptr=new node(d,tmp,tmp->next);
 						if(tmp->next!=NULL){
 							tmp->next->prev=ptr;
 						}else{
 							tail=ptr;
 							}
 						tmp->next=ptr; 

 					}

 				}

 			}

		}
		void reversing(){
			node *temp, *current=head;
			while(current!=NULL){
				temp = current->prev;
				current->prev=current->next;
				current->next=temp;
				current=current->prev;
			}
			if(temp!=NULL){
			head=temp->prev;
			}
		}
};
int main(){
	linkedlist a;
	a.insert_at_head(33);
	a.add_node(3);
	a.add_node(43);
	a.add_node(5);
	a.add_node(55);
	a.insertion_after_given_node(5,777);
	a.display();
	cout<<endl;
	a.reversing();
	a.display();
}
