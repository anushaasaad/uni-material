#include <iostream>
#include <string>
using namespace std;
struct node{
	int data;
	node *left, *right;
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
	node* search(node *temp, int d){
		if(temp==NULL || temp->data==d){
			return temp;
		}else if(root->data<d){
			search(temp->right, d);
		}else if(root->data>d){
			search(temp->left, d);
		}
	}
};
int main(){
	tree t;
	t.create(2);
	t.create(5);
	t.create(1);
	t.inorder(t.root);
	cout<<endl;
	t.postorder(t.root);
	cout<<endl;
	t.preorder(t.root);
	node *temp=t.search(t.root,2);
	cout<<endl;
	cout<<" "<<temp->data <<" ";
}
