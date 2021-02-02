#include <iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
struct node {
	int data;
	node *next;
};
class linkedlist{
	public:
	node *head, *tail;
	public:
		linkedlist(){
			head=NULL;
			tail=NULL;
		}
		void add_node(int d){
			node *tmp = new node;
			tmp->data = d;
			tmp->next = NULL;
			if(head == NULL)
			{
				head = tmp;
				tail= tmp;
				tail->next=head;
				
			}else{
				tmp->next = tail->next;
				tail->next=tmp;
				//tail=tmp;
				}
		}
		void display(){
			node *tmp=head;
			while(tmp->next!=head){
				cout<<tmp->data <<" ";
				tmp=tmp->next;
			}
			cout<<tmp->data <<" ";
		}
		void deletenode(node* head){
			node *tmp=head->next;
			head->next=tmp->next;
			free(tmp);
		}

};

int main(){
	int n;
	linkedlist a;
	a.add_node(32);
	a.add_node(5);
	a.add_node(12);
	a.add_node(40);
	a.add_node(2);
	a.add_node(05);
	a.add_node(1);
	a.add_node(4);
	a.display();
	a.deletenode(a.head);
	cout<<"\n";
	a.display();
}
