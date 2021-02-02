#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next; 
}; 
class linkedlist{
	node *head, *tail;
	public:
	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	
	void add_node(int n)
	{
		node *temp = new node;
		
		temp->data = n;
		temp->next = NULL;
		if(head==NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail= tail->next;
		}
	}	
	void bubble_sort(int size)
    {     
        int i,j,k=0;
        node *temp=head;
        node *temp2=head;
        node *temp1=temp->next;
        while(temp!=NULL)
        { 
        for(i=0;i<size-1;i++)
        {    
            temp=head;
            temp2=head;
            temp1=temp->next;
            for(j=0;j<size-i-1;j++)
            {  
                if(temp->data>temp1->data)
                {  
                    k=1;
                    if(temp==head)
                    { 
                        temp->next=temp1->next;
                        temp1->next=temp;
                        head=temp1;
                    }
                    else 
					if(temp->next==tail)
                    {   
                    temp2->next=temp1;
                    temp1->next=temp;
                    temp->next=NULL;
                    tail=temp;
                    }else{
	                    temp2->next=temp->next;
	                    temp->next=temp1->next;
	                    temp1->next=temp;
                    }
                        
                }else {
                    k=0;
                }
                if(j>0)
                {
                    temp2=temp2->next;
                }
                else
                {
                    temp2=head;
                }
            
                if(temp!=tail && k==1)
                {
                
                temp=temp1->next;
                temp1=temp->next;}
                else 
				if(k==0)
                {
                    temp=temp->next;
                    temp1=temp1->next;
                }
            }
        }
        break;
        }			 
    }
	
	node* swap(node* head) 
	{ 
       if (head->next == NULL) {
       	 return head;
		}
  
	    node* min = head; 
	  
	  
	    node* temp = NULL; 
	    node* ptr; 

	    for (ptr = head; ptr->next != NULL; ptr = ptr->next) 
		{ 
	        if (ptr->next->data < min->data) { 
	            min = ptr->next; 
	            temp = ptr; 
	        } 
	    } 
  
     
	    if (min != head) {
	    	head = min;
		    temp->next = head;
		    node* temp = min->next; 
		    min->next = head->next; 
		    head->next = temp; 
		}
	    head->next = swap(head->next); 
	  
	    return head; 
} 
   
	void selection_sort(node** temp) 
	{ 
	    if ((*temp) == NULL) 
	        return; 
	   
	    *temp = swap(*temp);
			node* temp1 = head; 
		    while(temp1->next!=NULL)
		    {
		    	temp1 = temp1->next;
			}
		
			tail = temp1; 	 
		} 


	void insertion_sort(node **tmp) 
	{ 
	    node *temp = NULL; 
	  
	     
	    node *cur = head; 
	    while (cur != NULL) 
	    { 
	        node *next = cur->next; 
	        insert(&temp, cur);  
	        cur = next; 
	    } 
	      head = temp; 
	} 
  
	void insert(node** temp, node* temp2) 
	{ 
		    node* cur; 
		    if (*temp == NULL || (*temp)->data >= temp2->data) 
		    { 
		        temp2->next = *temp; 
		        *temp = temp2; 
		    } 
		    else
		    { 
		     
		        cur = *temp; 
		        while (cur->next!=NULL && 
		               cur->next->data < temp2->data) 
		        { 
		            cur = cur->next; 
		        } 
		        temp2->next = cur->next; 
		        cur->next = temp2; 
		    } 
		    node* temp1 = head; 
			
		    while(temp1->next!=NULL)
		    {
		    	temp1 = temp1->next;
			}
		
			tail = temp1; 
			} 
		  node * getHead()
		  {
		  	return head;
 	 }
	void print()
	{
		node *temp = head;
		while(temp!=NULL)
		{
			cout << temp->data << " " ;
			temp = temp->next;
		}
		cout << head->data;
		cout << tail->data;
	}
};

int main()
{

	linkedlist l;
	l.add_node(1);
	l.add_node(7);
	l.add_node(19);
	l.add_node(14);
	l.add_node(6);
	l.add_node(10);
	l.add_node(8);
	l.add_node(5);

	struct node *head = l.getHead();
	cout << "Before Sorting:\n";
	l.print();
	cout << "\n";
	cout <<"Bubble Sort\n";
	l.bubble_sort(8);
	l.print();
	cout << "\nSelection Sort\n";
	l.selection_sort(&head);
	l.print();
	cout << "\nInsertion Sort\n";
	l.insertion_sort(&head);
	l.print();
}
