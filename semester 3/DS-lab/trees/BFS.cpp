#include <iostream>
#define MAX_SIZE 5
using namespace std;
struct node{
	int data;
	node *left, *right;
	node *next;
};
class queue{
    private:
    node* head;
    node* tail;
    public:
    queue()
    {
        head=NULL;
        tail=NULL;
    }
    void en_queue(int insert)
    {
       
        node* temp=new node;
        temp->next=NULL;
        temp->data=insert;
       
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        
    }
    int de_queue()
    {
        
        node* temp1=NULL;
        if(is_empty()==false)
        {
            temp1=head;
            head=head->next;
            return temp1->data;

        }
        else
        {
            return 0;
        }
        

    }
    bool is_empty()
    {
        if(head==NULL)
        return true;
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
	int BFS(int d,node *temp, queue &q){
		if(!q.is_empty()){
			int s=q.de_queue();
			cout<<s <<" ";
			if(s==d){
				return s;
			}else{
				if(temp->left!=NULL){
					q.en_queue(temp->left->data);
				if(temp->right!=NULL){
					q.en_queue(temp->right->data);
					}
					BFS(d,temp->left,q);
					BFS(d,temp->right,q);
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
	queue q;
	q.en_queue(t.root->data);
	if(t.BFS(6,t.root,q)==6){
		cout<<endl<<"YES Present In Tree";
    }else{
        cout<<endl<<"NOt Present In Tree";
    }
	
	}

 
