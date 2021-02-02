#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;

};
class linked_list{
    node *head, *tail;
    public:
    linked_list(){
        head=NULL;
        tail=NULL;
    }
    void insert_tail(int d){
        node *temp=new node;
        temp->data=d;
        if (head==NULL)
        {
            head=temp;
            tail=temp;
            tail->next=head;
        }else{
            temp->next=tail->next;
            tail->next=temp;
           // tail=temp;
        }
    }
    void insert_head(int d){
        node *temp=new node;
        temp->data=d;
        temp->next=tail->next;
        tail->next=temp;
    }
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
int main(){
    linked_list l;
    l.insert_tail(4);
    l.insert_tail(10);
    l.insert_head(100);
    l.insert_head(20);
    l.insert_tail(45);
    l.display();
}
