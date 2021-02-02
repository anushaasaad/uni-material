#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;

};
class linked_list{
    node *head, *tail;
    public:
    linked_list(){
        head=NULL;
        tail=NULL;
    }
    void add_at_last(int d){
        node *temp = new node;
        temp->data=d;
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            temp->next=NULL;
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
    }
//    void delete_node(int d){
//    	node *temp=head;
//    	if(temp->data==d){
//    			temp->prev->next=temp->next;
//
//		}else{
//				temp=temp->next;
//			}
//		
//	}
    void display(){
        node *temp=head;
        while (temp->next!=head)
        {
            cout<<" " <<temp->data;
            temp=temp->next;
        }
        cout<<" " <<temp->data;
    }
};
int main()
{
    linked_list l;
    
    l.add_node(10);
    l.add_node(190);
    l.add_node(11);
    l.add_node(3);
    l.display();
}
