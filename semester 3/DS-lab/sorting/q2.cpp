#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class linked_list
{
	private:
		node *head,*tail;
	public:
		linked_list()
		{
			head=NULL;
			tail=NULL;
		}
		node* get_head()
		{
			return head;
		}
		void add_node(int n)
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
		void print()
		{
			node* temp=head;
			while(temp!=NULL){
				cout<<temp->data <<" ";
				temp=temp->next;
			}
			cout<<endl;
		}


		void bubble_sort(int size)
		{
			node *temp=head; 
			int temp1; 
				while(temp!=NULL)
			{      
			 for(int i=0;i<size-1;i++){
			      temp=head;
			      for(int j=0;j<size-i-1;j++){
					if (temp->data > temp->next->data) 
					{
					  temp1=temp->data;
					  temp->data=temp->next->data;
					  temp->next->data=temp1; 
					}
					temp = temp->next;
				}
			}
				break;
		}
		

	}

};
int main()
{
	linked_list a;
	a.add_node(1);
	a.add_node(66);
	a.add_node(3);
	a.add_node(2);
	a.add_node(64);
	a.add_node(24);
	a.print();
	a.bubble_sort(6);
	a.print();
	
}

