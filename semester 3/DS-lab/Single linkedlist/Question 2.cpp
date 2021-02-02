#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class linked_list{
	private:
      node *head,*tail;
	public:
	linked_list(){
        head = NULL;
        tail = NULL;
    }
    void add_node(int n){
    	node *tmp = new node;
    	tmp->data=n;
    	tmp->next=NULL;
    	if(head==NULL){
    		head=tmp;
    		tail=tmp;
		}else{
		tail->next=tmp;
		tail=tail->next;
	   }
   }
    node* get_head(){
    	return head;
	}
	void display(){
	node* tmp=head;
		while(tmp!=NULL){
			cout<<"value: " <<tmp->data <<" " <<endl;
			tmp=tmp->next;
		}
}
};
void Average(linked_list* x,linked_list* y){
		node *tmp=x->get_head();
		int i,j,k=0;
		float avg=0;
		for(i=0; i<9; i++){
			for(j=0; j<4; j++){
				avg+=tmp->data;
				tmp=tmp->next;
			}
			avg=avg/4;
			y->add_node(avg);
			tmp=x->get_head();
			for(k=0;k<i;k++){
            tmp=tmp->next;
        }
}
    //x->display();
    //cout<<"Average:" <<endl;
	//y->display();
}
int main(){
	linked_list num;
	linked_list avg;
	int n=12,x;
	for(int i=0; i<n; i++){
		cout<<"enter number " <<i <<":";
		cin>>x;
		num.add_node(x);
	}
	Average(&num,&avg);
	num.display();
	cout<<"Average:" <<endl;
	avg.display();
	return 0;
}
	
