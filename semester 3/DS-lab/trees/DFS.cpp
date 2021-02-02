#include <iostream>
#define MAX_SIZE 5
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
		    return a[temp];
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
	int DFS(int d,node *temp, stack &s){
    
        if(!s.isempty()){
			int n=s.peek();
			cout<<n <<" ";
			if(n==d){
				return n;
			}else{
				if(temp->left!=NULL){
					s.push(temp->left->data);
					if(temp->right!=NULL){
						s.push(temp->right->data);
					}
					DFS(d,temp->left,s);
					DFS(d,temp->right,s);
				}
			}
		}
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
	t.create(2);
	t.create(5);
	t.create(1);
	t.create(6);
	t.create(4);
	//t.inorder(t.root);
	cout<<endl;
	stack s;
	s.push(t.root->data);
	if(t.DFS(6,t.root,s)==6){
		cout<<endl<<"YES Present In Tree";
    }else{
        cout<<endl<<"NOt Present In Tree";
    }
	
	}

