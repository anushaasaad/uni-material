#include <iostream>
#include <fstream>
using namespace std;
struct node{
	int data;
	node *left, *right;
	node *next;
};
class stack{
	int a[10];
	int n=10;
	int top=-1;
	public:
		void push(int data){
			top++;
			a[top]=data;
		}
		int pop(){
		   int temp=top;
		    top--;
		}
		int peek(){
			return a[top];
		}
		bool isfull(){
			if(top==n-1){
				return true;
			}else{
				return false;
			}
		}
		bool isempty(){
			if(top<0)
				{
					return true;
				}
				else
				{
					return false;
				}
		}
};
class tree{
	public:
	node *root;
	tree(){
		root=NULL;
	}
	void create(int d){
		node *temp=new node;
		node *current , *parent;
		temp->data=d;
		temp->left=NULL;
		temp->right=NULL;
		if(root==NULL){
			root=temp;
		}else{
			current=root;
			while(current!=NULL){
				parent=current;
				if(d<parent->data){
					current=current->left;
					if(current==NULL){
						parent->left=temp;
						return;
					}
				}else{
					current=current->right;
					if(current==NULL){
						parent->right=temp;
						return;
					}
				}
			}
		}
	}
	stack print_sum(stack &s){
		stack s1;
		int sum=0;
	    fstream outfile;
	    outfile.open("Q2output.txt", ios::out | ios::app);
		while(s.isempty()!=true)
			{
		        int temp1=s.peek();
		        s.pop();
		        sum=sum+temp1;
		        s1.push(temp1);
		    }
        outfile<<sum<<"-";
        cout<<sum<<"-";
        while(s1.isempty()!=true)
        {
            int temp2=s1.peek();
            s1.pop();
            s.push(temp2);
       	 	}
       	 	outfile.close();
       	 	return s;
		}
	
	void pathwisesum(node *temp, stack &s){
        if(temp==NULL){
			return;
		}
		s.push(temp->data);
		pathwisesum(temp->left,s);
		if(temp->left==NULL && temp->right==NULL){
			s=print_sum(s);
		}	
		pathwisesum(temp->right,s);
		s.pop();
	}
	
	
    
	void inorder(node *temp){
		if (temp == NULL) 
        return; 
		inorder(temp->left);
		cout<<" " <<temp->data;
		inorder(temp->right);
	}
	void postorder(node *temp){
		if (temp == NULL) 
        return; 
		postorder(temp->left);
		postorder(temp->right);
		cout<<" " <<temp->data;
	}
	void preorder(node *temp){
		if (temp == NULL) 
        return; 
		cout<<" " <<temp->data;
		preorder(temp->left);
		preorder(temp->right);
	}	
};
int main(){
	tree t;
	int n;
	fstream myfile;
	myfile.open("Q2input.txt",ios::in);
	for(int i=0; !myfile.eof(); i++)
	{
		int x;
		//cin>>x;
		myfile>>x;
		t.create(x);	
	}
	myfile.close();
	t.inorder(t.root);
	cout<<endl;
	stack s;
	//s.push(t.root->data);
	t.pathwisesum(t.root,s);
}

