#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
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
        temp->prev=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            temp->prev=tail;
            tail->next=temp;
            temp->next=NULL; 
            tail=temp;
        }
    }
    void insert_at_head(int d){
        node *temp=new node;
        temp->data=d;
        temp->next=head;
        temp->prev=NULL;
        head=temp;
    }
    void display(){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data <<" ";
            temp=temp->next;
        }
    }
    void delete_head(){
        node* temp=head->next;
        head=temp;
        head->prev=NULL;
    }
    void delete_tail(){
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
    void insert_after_given_node(int d, int n){
        node *temp=new node, *temp1=head;
        temp->data=d;
        temp->next=NULL;
        temp->prev=NULL;
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
};
int main(){
    linkedlist l;
    l.add_at_last(5);
    l.add_at_last(9);
    l.add_at_last(44);
    l.add_at_last(10);
    l.insert_at_head(100);
    l.display();
    l.delete_head();
    l.delete_tail();
    cout<<"\n";
    l.display();
    l.insert_after_given_node(200,9);
    cout<<"\n";
    l.display();
}
