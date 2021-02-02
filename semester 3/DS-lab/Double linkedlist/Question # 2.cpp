#include "Question # 2.h"
#include <iostream>
using namespace std;
linked_list::linked_list(){
	head=NULL;
	tail=NULL;
}
void linked_list::add_node(int n){
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		tmp->prev=NULL;
		if(head == NULL)
		{
			head = tmp;
			tail = tmp;
			
		}
		else
		{
			tmp->prev=tail;
			tail->next = tmp;
			tail = tmp;
			}
}
void linked_list::display(){
		node* tmp = new node;
		tmp=head;
		while(tmp!=NULL){
			cout<<"value: " <<tmp->data <<" " <<endl;
			tmp=tmp->next;
		}
}
node* linked_list::get_head(){
    	return head;
}
void linked_list::search(int a, int b)
{
	node *tmp=head; 
	int count=1; 
	while(tmp!=NULL)
	{
		if(tmp->data==a)
		{
			cout << "cabin is found at: " << count << endl;
			while(tmp!=NULL)
			{
				if(tmp==head)
				{
                    int x=1;
					while (tmp!=NULL)
					{
						if(tmp->data==b)
						{
							cout << "Member has been found at cabin no: " << x<< endl; 
                            return; 
						}
						tmp=tmp->next; 
                        x++; 
					}
				}
                tmp=tmp->prev; 
			} 
		}
		tmp=tmp->next; 
    	count++; 
    }
}
//void linked_list::insert_head(int x){
//	node *tmp=new node;
//	tmp->data=x;
//	tmp->next=head;
//	head=tmp;
//}
//void linked_list::deletefromend(){
//	node *tmp=head;
//	while(tmp!=NULL){
//		if(tmp->next==tail){
//			tail=tmp;
//			tail->next=NULL;
//		}
//	}
//}
////void linked_list::removeduplicates(){
////	node *tmp=head;
////	while(tmp!=NULL){
////	//	if(tmp->data==)
////	}
////}
//void linked_list::reverse(){
//	node* current=head;
//	node *tmp1=NULL;
//	node *tmp2=NULL;
//	while(current!=NULL){
//		tmp1=current->next;
//		current->next=tmp2;
//		tmp2=current;
//		current=tmp1;
//	}
//	head=tmp2;
//	display();
//}
int main(){
	linked_list a;
	a.add_node(3);
	a.add_node(5);
	a.add_node(2);
	a.add_node(4);
	a.add_node(8);
	a.add_node(9);
	cout<<" \n";	
	a.display();
	a.search(4,2);
}
