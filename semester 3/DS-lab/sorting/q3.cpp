#include<iostream>
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
    void add_node(int d){
        node *temp=new node;
        temp->data=d;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }else
        {
            tail->next=temp;
            tail=tail->next;
        }
    }
    void print(){
            node* temp=head;
            while (temp!=NULL)
            {
                cout<< temp->data <<" " ;
                temp=temp->next;
            }
            
        }
    void bubblesort(int n){
        node* temp=head, *temp1;
        while (temp!=NULL)
        {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n-1; j++)
            {
                if(temp->data > temp->next->data){
                    temp1 = temp;
                    temp = temp->next;
                    temp->next = temp1;
                }
                temp=temp->next;
                }
            
            }
        break;
        }
    }
    void selectionsort(int n){
        node* temp=head, *temp1;
        while (temp!=NULL)
        {
            for (int i = 0; i < n; i++){
                for (int j = i+1; j < n; j++){
                    if(temp->data > temp->next->data){
                        temp=temp->next;
                    }
                    temp1 = temp;
                    temp = temp->next;
                    temp->next = temp1;
                 }
            }
            break;
        } 
    } 
};
int main()
{
    linked_list a;
    a.add_node(3);
    a.add_node(1);
	a.add_node(66);
	a.add_node(3);
	a.add_node(2);
	a.add_node(64);
	a.add_node(24);
    a.print();
    cout<<"\nBUBBLE sort" <<endl;
    a.bubblesort(7);
    a.print();
//    cout<<"\nSelection sort" <<endl;
//    a.selectionsort(7);
//    a.print();
}
