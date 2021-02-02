#include <iostream>
using namespace std;
struct node{
	int data;
	node *left, *right;
	node(int data) {
		this->data = data;
		}
};
class tree{
	public:
	node *root;
	tree(){
		root=NULL;
	}
	void addNode(int key) {
		node *newNode = new node(key);
		if (root == NULL) {
			root = newNode;
		}else{
		node *focusNode = root;
		node *parent;
		while (true) {
			
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
	t.addNode(2);
	t.addNode(5);
	t.addNode(1);
	t.inorder(t.root);
	cout<<endl;
	t.postorder(t.root);
	cout<<endl;
	t.preorder(t.root);
}
