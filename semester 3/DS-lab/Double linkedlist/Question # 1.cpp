#include<iostream>
using namespace std;
struct node {
	int data;
	node *next;
	node *prev;
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
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		tmp->prev=NULL;
		if(head == NULL)
		{
			head = tmp;
			tail = tmp;
			
		}else{
			tmp->prev=tail;
			tail->next = tmp;
			tail = tmp;
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
};
int GetNth(struct node* head, int index){
	int count=0;
	node *tmp=head;
	while(tmp!=NULL){
		if(index==count){
			return(tmp->data);
			count++;
		}else{
			count++;
		}
		tmp=tmp->next;
	}
}
int main(){
	int n;
	linkedlist a;
	a.add_node(32);
	a.add_node(5);
	a.add_node(12);
	a.add_node(40);
	a.display();
	cout<<"\nenter index value you want:";
	cin>>n;
	cout<<"\n";
	//cout<<GetNth(a.head, 7);
	if(GetNth(a.head,n)!=0){
		cout<<"Value at Index:"	<<GetNth(a.head,n);
		 }else{
		 cout<<"ERROR.NO value at index:" <<n;
		 }
}
