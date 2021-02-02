#include <iostream>
#include <string>
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
	int getheight(node* temp){
		if(temp==NULL){
			return -1;
		}else{
			return temp->height;
		}
	}
	int balance_factor(node* temp){
		if(temp==NULL){
			return 0;
		}
		return getheight(temp->left)-getheight(temp->right);
	}
	node* rotate_right(node *temp){
		node *temp1=temp->left;
		temp->left=temp1->right;
		temp1->right=temp;
		temp1->height=max(getheight(temp1->left),getheight(temp1->right))+1;
		temp->height=max(getheight(temp->left),getheight(temp->right))+1;
		return temp1;
		
	}
	node* rotate_left(node *temp){
		node *temp1=temp->right;
		temp->right=temp1->left;
		temp1->left=temp;
		temp1->height=max(getheight(temp1->left),getheight(temp1->right))+1;
		temp->height=max(getheight(temp->left),getheight(temp->right))+1;
		return temp1;
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
				int bf=balance_factor(temp);
				if(bf>1 && d >temp->left->data){
					return rotate_right(temp);
				}
				if(bf > 1 && temp->left->data < d)
		        {	temp->left = rotate_left(temp->left);
		            return rotate_right(temp);
		        }
			}else if (d > temp->data){
           		temp->right =create(temp->right, d);
           		int bf=balance_factor(temp);
				if(bf>1 && d < temp->right->data){
					return rotate_left(temp);
				}
				if (bf < -1 && d < temp->right->data){
		        temp->right = rotate_right(temp->right);
			    return rotate_left(temp);
			}
			}else
					return temp;
			/*	temp->height=max(getheight(temp->left),getheight(temp->right))+1;
				int bf=balance_factor(temp);
				//left to left
				if(bf>1 && d >temp->left->data){
					return rotate_right(temp);
				}
				//left right
				else if(bf > 1 && temp->left->data < d)
		        {	temp->left = rotate_left(temp->left);
		            return rotate_right(temp);
		        }
		        //right right
		        else if(bf>1 && d < temp->right->data){
					return rotate_left(temp);
				}
				//right left
				else if(bf < -1 && d < temp->right->data){
		        temp->right = rotate_right(temp->right);
			    return rotate_left(temp);
			}*/
		        return temp;
		}
	
/*	node* delete_node(int d, node *temp){
		if(temp==NULL){
			return NULL;
		}else if(d<temp->data){
			temp->left = delete_node(d, temp->left);
		}else if(d>temp->data){
			temp->right = delete_node(d, temp->right);
		}
		
	}*/

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
	t.postorder(t.root);
	cout<<endl;
	t.preorder(t.root);
	//node *temp=t.search(t.root,2);
	cout<<endl;
	cout<<endl;
	//t.delete_node(5,t.root);
	//t.inorder(t.root);
}
