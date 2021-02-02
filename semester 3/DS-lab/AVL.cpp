#include<iostream>
using namespace std;
struct node{
	int data;
	node *left, *right;
	int height;
};
class AVL{
	public:
	node *root;
	AVL(){
		root=NULL;
	}
	int max(int a, int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}
	int getheight(node *temp){
		if(temp==NULL){
			return -1;
		}else{
			return temp->height;
		}
	}
	node* rotateright(node *temp){
		node *temp1=temp->left;
		temp->left=temp1->right;
		temp1->right=temp;
		temp->height=max(getheight(temp->left),getheight(temp->right))+1;
		temp1->height=max(getheight(temp1->left),getheight(temp1->right))+1;
		return temp1;
	}
	node* rotateleft(node *temp){
		node *temp1=temp->right;
		;
	} 
	node* create(node *temp, int d){
		if(temp==NULL){
			node *temp = new node;
	       	temp->data=d;
			temp->left=NULL;
			temp->right=NULL;
	        temp->height = -1;
	        if (root == NULL)
	            root = temp;
	
	        return temp;
			}else if(d<temp->data){
				temp->left = create(temp->left, d);
			
			}else if (d > temp->data){
           		temp->right =create(temp->right, d);
           		
			}
		        return temp;
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
int main()
{
	AVL t;
	int n,data;
    cout<<"Enter number of nodes to enter" << endl;
    cin>>n;
    node *temp=NULL;
    for (int i=0; i<n; i++){
        cout << "Enter node data " <<endl;
        cin>>data;
        temp=t.create(temp,data); 
    }
	cout<<endl;
	t.inorder(t.root);
	cout<<endl;
}
