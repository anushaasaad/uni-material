#include <iostream>
using namespace std;
struct node{
	int data;
	node *next, *prev;
};
class linked_list{
	node *head, *tail;
	public:
	linked_list(){
		head=NULL;
		tail=NULL;
	}
	void add_node(int d){
		node *temp=new node;
		temp->data=d;
		temp->next=NULL;
		temp->prev=NULL;
		if(head==NULL){
			head=temp;
			tail=temp;
		}else{
			tail->next=temp;
			temp->next==NULL;
			temp->prev=tail;
			tail=temp;
		}
	}
	void removing_dup(){
		node *temp1=head, *temp2;
		while(temp1!=NULL && temp1->next!=NULL){
			temp2=temp1;
			while (temp2->next!=NULL)
			{
			if(temp1->data==temp2->next->data){
					temp2->next=temp2->next->next;
			}else{
				temp2=temp2->next;
				}
			}
		temp1=temp1->next;
		}
	}
	void swap_nodes(int d){
		node *temp=head, *temp1, *prev;
		while(temp!=NULL && temp->data!=d){
			prev=temp;
			temp=temp->next;
			temp1=temp->next;
		}
			if(temp->data==d){
				prev->next=temp1;
				temp->next=temp1->next;
				//temp1=temp->next;
				temp1->next=temp;
			}else{
				temp=temp->next;
			}
		}
	void print(){
		node *temp=head;
		while (temp!=NULL)
		{
			cout<<temp->data <<" ";
			temp=temp->next;
		}
		

	}
	void sort(){
		node *i, *j;
		for(i=head; i!=NULL; i=i->next){
			for(j=i->next; j!=NULL; j=j->next){
				if(i->data>j->data){
					int temp= i->data;
					i->data=j->data;
					j->data=temp;
				}
			}
		}
	}
};
int main(){
	linked_list l;
	l.add_node(1);
	l.add_node(2);
	l.add_node(1);
	l.add_node(3);
	l.add_node(2);
	l.add_node(12);
	l.add_node(3);
	l.add_node(4);
	l.add_node(12);
	l.print();
	cout<<"\n";
	l.removing_dup();
	l.sort();
	l.print();
	cout<<"\nswapping nodes\n";
	l.swap_nodes(2);
	l.print();
	

}
