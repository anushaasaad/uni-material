#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
class detect_loop
{
	node *head,*tail;
public:
	detect_loop()
	{
		head=NULL;
		tail=NULL;
	}
	void insert(int n)
	{
		node *temp=new node;
		temp->data=n;
		temp->next=NULL;
		if(head!=NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=tail->next;
		}
	}
	bool find_loop()
	{
		int i=0;
		node *temp1=new node;
		node *temp2=new node;
		temp1=head;
		temp2=head;
		while(temp1!=NULL)
		{
			while(temp2!=NULL)
			{
				if(temp1==temp2)
				{
					i++;
					if(i>1)
					{return true;}
				}
				temp2=temp2->next;
			}
			temp1=temp1->next;
		}
		return false;
	}
};
int main()
{
	detect_loop dp1;
	dp1.insert(10);
	dp1.insert(20);
	dp1.insert(30);
	dp1.insert(40);
	if(dp1.find_loop())
	{cout<<"FOUND"<<endl;}
	else
	{cout<<"NOT FOUND"<<endl;}
	getch();
}
