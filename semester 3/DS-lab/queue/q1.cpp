#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class queue{
	node *head,*tail;
	public:
		queue(){
			head=NULL;
			tail=NULL;
		}
		void add_node(int data){
			node *temp=new node;
			temp->data=data;
			temp->next=NULL;
			if(isempty()==true){
				head=temp;
				tail=temp;
			}else{
				tail->next=temp;
				tail=temp;
				tail->next=NULL;
			}
			
		}
		bool isempty(){
			if(head==NULL && tail==NULL){
				return true;
			}else{
			return false;
			}
		}
		void dequeue(){
			head=head->next;
			}
		int count(){
			node *temp=head;
			int count=0;
			while(temp!=NULL){
				count++;
				temp=temp->next;
			}
			return count;
		}
		
	    void display(){
	    	int x=0;
	    	if(isempty()){
	    		cout<<"no moe customers" <<endl;
			}
	    	node *temp=head;
	    	while(temp!=NULL){
	    		cout<<"CUSTOMER " <<x+1 <<"bill:" <<temp->data <<endl;
	    		temp=temp->next;
	    		dequeue();
	    		x++;
			}
		}
};
int main(){
	queue q;
	q.add_node(200);
	q.add_node(300);
	q.add_node(500);
	q.add_node(200);
	q.add_node(300);
	q.add_node(500);
	q.display();
}
