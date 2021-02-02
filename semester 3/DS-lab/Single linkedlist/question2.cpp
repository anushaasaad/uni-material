#include "question1.h"
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
int linked_list::count(){
	node *tmp=head;
	int count=0;
	while(tmp!=NULL){

		count++;
	    tmp=tmp->next;
	}
	return count;
}
int main(){
	linked_list a;
	a.add_node(1);
	a.add_node(2);
	a.add_node(3);
	a.add_node(2);
	a.add_node(4);
	a.add_node(2);
	int c=a.count();
	cout<<"TOTAL COUNT OF NODES:" <<c;
	return 0;
}
