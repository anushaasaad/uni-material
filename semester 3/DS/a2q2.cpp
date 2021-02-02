#include <iostream>
#include <fstream>
using namespace std;
class queue
{
	int* myqueue;
	int front,rear,size;
	public:
		queue(int size1)
		{
			front=0;
			rear=-1;
			size=size1;
			myqueue=new int[size];
		}
		bool empty()
		{
			return (rear==-1);
		}
		bool full()
		{
			return (rear==size-1);
		}
		void enqueue(int val)
		{   
			if(full())
			{
				cout<<"SORRY QUEUE IS FULL\n";
			}
			else
			{ 
				rear++;
				myqueue[rear]=val;
			}
		}
		int dequeue()
		{
			if(empty())
			{
				cout<<"Sorry QUEUE is empty\n";
				return 0;
			}
			else
			{
				if(front==rear)
				{
					front=0;
					rear=-1;
					return (myqueue[front]);
				}
				else
				{  int temp=0,i=1,temp1=myqueue[front];
					while(temp!=rear)
					{
					myqueue[temp]=myqueue[i];
					i++;
					temp++;
					}
					rear--;
					return temp1;}
				}
				}
void displayQueue()
    { int i;
if(empty()) {
cout << endl << "Queue is Empty!!" << endl;
        }
else {
cout << endl << "Front = " << front;
cout << endl << "Queue elements : ";
for(i=front; i<=rear; i++)
cout << myqueue[i] << "\t";
cout << endl << "Rear = " << rear << endl;
        }
    }
    void swap(queue &obj)
    {   int val;
       for(int i=0;i<size;i++)
       {
	   val=obj.dequeue();
    		enqueue(val);}
	}
    

		
};
int main()
{  
	ifstream myfile("input004.txt");
	int size,val,val1,val2,max=0;
	myfile>>size;
	cout<<size<<endl;
	int arr[size];
	queue q1(size),q2(size),q3(size),q4(size);
	
	for (int i=0;i<size;i++)
	{
		
		myfile>>val;
		cout<<val<<" ";
		q1.enqueue(val);
		
	}
	cout<<endl;
	for (int i=0;i<size;i++)
	{
		
		myfile>>val;
		cout<<val<<" ";
		q2.enqueue(val);
	}
	cout<<endl;

	for (int i=0;i<size;i++)
	{
		myfile>>val;
		cout<<val<<" ";
		if(val>max)
		max=val;
		q3.enqueue(val);
	}
	cout<<endl;
//	cout<<"max="<<max<<endl;
	int count=0;
	while(1)
	{ 
		for(int i=0;i<size;i++)
		{
			val1=q2.dequeue();
		//	cout<<"HELLO"<<endl;
			val2=q3.dequeue();
		//	cout<<"HELLO1"<<endl;
			val=q1.dequeue();
		//	cout<<"HELLO2"<<endl;
			if(val2!=0)
			{  if(val2==max)
			{  // cout<<"max="<<endl;
				max=val2-val1;
			}
			val2=val2-val1;
			if(val2<0)
			{
				cout<<"ERROR FUNCTION CANT PROCESS";
				return 1;
			}
			if(val2==0)
			{
				count++;
				q4.enqueue(val);
				if(count==size)
				break;
				
			}
			q3.enqueue(val2);
			q2.enqueue(val1);
			q1.enqueue(val);
			}
		}
		if(count==size)
		break;
	}
	//q1.swap(q4);
	q4.displayQueue();
}
