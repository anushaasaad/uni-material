#include <iostream>
#include <string>
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
	int max(int a, int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}
	int getheight(node* temp){
		if(temp==NULL){
			return 0;
		}else{
        int l=getheight(temp->left);
        int r=getheight(temp->right);
        if(l>r)
            return l+1;
        else
            return r+1;
    	}
	}
	void levelwisesum(int* sum,node *temp, queue &q, int level){
		if(temp==NULL)
			return;
        while(!q.is_empty()){
			int s=q.de_queue();
			sum[level]+=s;
		}
		if(temp->left!=NULL){
			q.en_queue(temp->left->data);
		}
		if(temp->right!=NULL){
			q.en_queue(temp->right->data);
		}
		levelwisesum(sum,temp->left,q,level+1);
		levelwisesum(sum,temp->right,q, level+1);
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
	cout<<"Enter number of nodes:" <<endl;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"Enter node element[" <<i <<"]:";
		int x;
		cin>>x;
		t.create(x);	
	}
	//t.inorder(t.root);
	cout<<endl;
	int level=t.getheight(t.root);
	queue q;
	q.en_queue(t.root->data);
	int sum[level] = { 0 }; 
	t.levelwisesum(sum,t.root,q,0);
	for(int i=0; i<level; i++){
		cout<<"-";
		cout<<sum[i];
	}
}

