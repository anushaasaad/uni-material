#include<iostream>
using namespace std;
struct BSTnode
{
	int data;
	BSTnode* left;
	BSTnode* right;
};
class BST
{
	public:
		BSTnode* root;
		
	BST()
	{
		root=NULL;	
	}
	BSTnode* get_root()
	{
		return root;
	}
	BSTnode* create(int value)
	{
		BSTnode* newnode = new BSTnode();
		newnode->data = value;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	BSTnode* insert(BSTnode* root , int value)
	{
		if(root==NULL)
		{
			root = create(value);
		}
		else if( value > root->data)
		{
			root->right = insert(root->right , value);
		}
		else
		{
			root->left = insert(root->left , value);
		}
	}
	BSTnode* inorder(BSTnode* root)
	{
		if(root!=NULL)
		{
			inorder(root->left);
			cout<<root->data<<" ";
			inorder(root->right);	
		}	
	}	
};
int main()
{
	BST obj;
	obj.root=obj.insert(obj.get_root(),5);
	obj.root=obj.insert(obj.get_root(),10);
	obj.root=obj.insert(obj.get_root(),2);
	obj.root=obj.inorder(obj.get_root());
	
}
