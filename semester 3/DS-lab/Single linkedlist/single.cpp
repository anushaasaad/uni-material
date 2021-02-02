#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class linkedlist{
    node *head, *tail;
    public:
    linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void add_at_last(int d){
        node *temp = new node;
        temp->data=d;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            tail->next=temp;
            tail=tail->next;
            tail=temp;
        }
    }
    void display(){
        node *temp;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data <<" ";
            temp=temp->next;
        }
    }
    void add_at_front(int d){
        node *temp = new node;
        temp->data=d;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            temp->next=head;
            head=temp;
        }
    }
    void insert_after(int d, int n){
        node *temp = new node, *temp1;
        temp->data=d;
        temp->next=NULL;
        temp1=head;
        while (temp1!=NULL){
            if(temp1->data==n){
                temp->next=temp1->next;
                temp1->next=temp;
                break;
            }else{
                temp1=temp1->next;
            }
     }
    }
    void delete_last(){
        node *temp1=head;
        while (temp1!=NULL)
        {
            if(temp1->next==tail){
            	tail=temp1;
            	temp1->next=NULL;
            }else{
                temp1=temp1->next;
            }
        }
    }
    void delete_head(){
    	node *temp=head->next;
    	head=temp;
	}
};
int main(){
    linkedlist l;
    l.add_at_last(5);
    l.add_at_last(9);
    l.add_at_front(11);
    l.add_at_last(55);
    l.add_at_front(4);
    l.insert_after(55,9);
    l.display();
  	l.delete_last();
  	l.delete_head();
 	cout<<" \n";
    l.display();
}
