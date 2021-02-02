#include "question3.h"
using namespace std;
linked_list::linked_list(){
		head = NULL;
		tail = NULL;
}
void linked_list::add_node(int n)
	{
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	if(head == NULL)
	{
	head = tmp;
	tail = tmp;
	}
	else
	{
	tail->next = tmp;
	tail = tail->next;
	}
}		
void linked_list::replace(int search, int n){
	node *tmp=head;
	while(tmp!=NULL){
		if(tmp->data==search){
			tmp->data=n;
		}
	 tmp=tmp->next;
	}
}
void linked_list::display(){
	if(head==NULL){
		cout<<"list is empty" <<endl;
	}
	struct node *tmp=head;
	while(tmp!=NULL){
		cout<<tmp->data <<" ";
		tmp=tmp->next;
}
}
int main(){
	linked_list a;
	a.add_node(1);
	a.add_node(2);
	a.add_node(3);
	a.add_node(2);
	a.add_node(4);
	a.add_node(2);
	a.replace(4,7);
	a.display();
	
	
	return 0;
}
