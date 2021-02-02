#include <iostream>
#include <fstream>
using namespace std;
struct node{
	int data;
	node *next;
};
class queue{
	public:
	node *front, *rear;
		queue(){
			front=NULL;
			rear=NULL;
		}
		void enqueue(int d){
			node *temp=new node;
			temp->data=d;
			temp->next=NULL;
			if(front==NULL){
				rear=NULL;
				front=temp;
				rear=temp;
			}else{
				rear->next=temp;
				rear=temp;
			}
		}
		void dequeue(){
			node *temp=front;
			if(front==NULL && rear==NULL){
				cout<<"Queue is empty" <<endl;
			}else{
				cout<<front->data;
				front =front->next;
			//	free(temp);
			}
		}
		void display(){
			node *temp;
			if(front==NULL && rear==NULL){
				cout<<"Queue is empty" <<endl;
			}else{
				temp=front;
				while(temp!=NULL){
					cout<<temp->data <<" ";
					temp=temp->next;
				}
			}
		}
		void sorting(queue &ob1, int size){//ob1=divided
		node *temp1=front, *temp2=ob1.front; 
		int temp,temp3; 
		while(temp1!=NULL && temp2!=NULL)
		{      
		 for(int i=0;i<size-1;i++){
    	    temp1=front;
    	    temp2=ob1.front;
		    for(int j=0;j<size-i-1;j++){
				if (temp2->data > temp2->next->data) 
				{
				  temp=temp1->data;
				  temp3=temp2->data;
				  temp1->data=temp1->next->data;
				  temp2->data=temp2->next->data;
				  temp1->next->data=temp; 
				  temp2->next->data=temp3;
				}
				temp1 = temp1->next;
				temp2 = temp2->next;
				}
			}
			break;
		}
	}
	void displayinfile(){
		ofstream file;
		file.open("output000.txt");
		while(front!=NULL){
			file<<front->data;
			front=front->next;
		}
		file.close();
	}
};
queue division(queue &ob1, queue &ob2){
		node *temp1=ob2.front ,*temp2=ob1.front; 
		queue q;
		while(temp1!=NULL && temp2!=NULL){
			q.enqueue(temp1->data/temp2->data);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		///l.display();
		return q;
}

int main(){
	ifstream myfile;
	myfile.open("input000.txt");
	queue q1;
    int n,x;
    cout<<"enter number of processes:";
    //cin>>n;
    myfile>>n;
    cout<<n <<endl;;
    cout<<"Enter elements of permutation of first n numbers:" <<endl;
    for(int i=0; i<n; i++){
    	myfile>>x;
    	cout<<x <<endl;
    	//cin>>x;
    	q1.enqueue(x);
	}
	cout<<"Enter units of qouta" <<endl;
	queue q2;
	for(int i=0; i<n; i++){
    	//cin>>x;
    	myfile>>x;
    	cout<<x <<endl;
    	q2.enqueue(x);
	}
	cout<<"Enter CPU time:" <<endl;
	queue q3;
	for(int i=0; i<n; i++){
    	//cin>>x;
    	myfile>>x;
    	cout<<x <<endl;
    	q3.enqueue(x);
	}
	myfile.close();
	cout<<"Units of Qouta :" <<endl;
	q2.display();
	cout<<endl;
	cout<<"CPU time:"  <<endl;
	q3.display();
	cout<<endl;
	queue q=division(q2,q3);
	cout<<"Divided :";
	q.display();
	cout<<endl;
	q1.display();
	q1.sorting(q,n);
	cout<<endl;
	cout<<"OUTPUT:" <<endl;
	q1.display();
	q1.displayinfile();
	
	
}
