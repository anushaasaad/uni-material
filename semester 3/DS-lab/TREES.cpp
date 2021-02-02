#include <iostream>
using namespace std;
struct node{
	int data;
	node *right, *left;
};
class tree{
	public:
	node *root;
	tree(){
		root=NULL;
	}
	node* getroot(){
		return root;
	}
	node *create(int d){
			node *temp=new node;
			temp->data=d;
			temp->left=NULL;
			temp->right=NULL;
			return temp;
			}
	
	node* add_node(int d , node *temp1){
			if(temp1==NULL){
				temp1=create(d);
			}else if(d<temp1->data){
				temp1->left=add_node(d,temp1->left);
				//return temp1;
			}else if(d>root->data){
				temp1->right=add_node(d,temp1->right);
				//return temp1;
			}
		}
	

	
	void inorder(node *root){
		if(root==NULL)
			return;
		inorder(root->left);
		cout<<root->data <<" ";
		inorder(root->right);
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
	t.root=t.add_node(2,t.getroot());
	t.root=t.add_node(5,t.getroot());
	t.root=	t.add_node(6,t.getroot());
	t.root=	t.add_node(1,t.getroot());
	t.root=	t.add_node(0,t.getroot());
	t.inorder(t.root);
	t.postorder(t.root);
}
