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
	void bubblesort(int n)
    {     
        int i,j;
        node *temp=head;
        node *temp1=temp->next;
        node *temp2=head;
        int x=0;
        while(temp!=NULL)
        { 
        for(i=0;i<n-1;i++)
        {    
            temp=head;
            temp1=temp->next;
            temp2=head;
            for(j=0;j<n-i-1;j++)
            {  
                if(temp->data > temp1->data)
                {  
                    x=1;
                    if(temp==head)
                    { 
                        temp->next=temp1->next;
                        temp1->next=temp;
                        head=temp1;
                    }
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
                    x=0;
                }
                if(j>0)
                {
                    temp2=temp2->next;
                }
                else
                {
                    temp2=head;
                }
            
                if(temp!=tail && x==1)
                {
                
                temp=temp1->next;
                temp1=temp->next;
				}
				if(x==0)
                {
                    temp=temp->next;
                    temp1=temp1->next;
                }
            }
        }
        break;
        }			 
    }
	
	node* swapping(node* head) 
	{ 
       if (head->next == NULL) {
       	 return head;
		}
  
	    node* temp = head; 
	  
	  
	    node* temp1 = NULL; 
	    node* p; 

	    for (p=head; p->next!=NULL;p=p->next) 
		{ 
	        if (p->next->data < temp->data) { 
	            temp = p->next; 
	            temp1 = p; 
	        } 
	    } 
  
     
	    if (temp != head) {
	    	head = temp;
		    temp1->next = head;
		    node* temp1 = temp->next; 
		    temp->next = head->next; 
		    head->next = temp1; 
		}
	    head->next = swapping(head->next); 
	  
	    return head; 
} 
   
	void selection_sort(node** temp) 
	{ 
	    if ((*temp) == NULL) {
	        return; 
	    }
	   
	    *temp = swapping(*temp);
			node* temp1 = head; 
		    while(temp1->next!=NULL)
		    {
		    	temp1 = temp1->next;
			}
			tail = temp1; 	 
		} 
	void insertionsort(node **tmp) 
	{ 
	    node *temp = NULL; 
	    node *temp1 = head; 
	    while (temp1 != NULL){ 
	        node *next = temp1->next; 
	        insertion(&temp, temp1);  
	        temp1= next; 
	    } 
	      head = temp; 
	} 
  
	void insertion(node** temp, node* temp1) 
	{ 
		    node* temp2; 
		    if (*temp == NULL || (*temp)->data >= temp1->data) 
		    { 
		        temp1->next = *temp; 
		        *temp = temp1; 
		    }else
		    { 
		     
		        temp2 = *temp; 
		        while (temp2->next!=NULL && 
		               temp2->next->data < temp1->data) 
		        { 
		            temp2 = temp2->next; 
		        } 
		        temp1->next = temp2->next; 
		        temp2->next = temp1; 
		    } 
		    node* temp3 = head; 
			
		    while(temp3->next!=NULL)
		    {
		    	temp3 = temp3->next;
			}
		
			tail = temp3; 
	} 
	 node * get_head(){
		return head;
 	 }
 	 void print(){
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

	linkedlist a;
	a.add_node(8);
	a.add_node(7);
	a.add_node(6);
	a.add_node(5);
	a.add_node(4);
	a.add_node(355);
	a.add_node(22);
	a.add_node(1);

	struct node *head = a.get_head();
	cout << "Orignal array:\n";
	a.print();
	cout << "\n";
	cout <<"\n Bubble Sorting\n";
	a.bubblesort(8);
	a.print();
	cout << "\nSelection Sorting\n";
	a.selection_sort(&head);
	a.print();
	cout << "\nInsertion Sort\n";
	a.insertionsort(&head);
	a.print();
}
