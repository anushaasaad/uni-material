#include<iostream>
using namespace std;

struct avl_node
{
    int data;
    avl_node* left;
    avl_node* right;
    int bf;

};
struct node
{
    int data;
    node* next;
};
class queue
{
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


int max(int a, int b)
{
    
    if (a > b)
        return a;
    else
    {
        return b;
    }
}
// get root balance factor
int height(avl_node *root)
{
    if (root == NULL)
        return 0;

    return root->bf;
}
//check if bf is balance
int baalance_factor(avl_node *root)
{
    if (root == NULL)
        return 0;
    return (height(root->left) - height(root->right));
}
class avl_tree
{
private:
    avl_node *root;

public:
    avl_tree()
    {
        root = NULL;
    }
    avl_node *new_node(int data)
    {
        avl_node *temp = new avl_node;
        
        temp->left = NULL;
        temp->right = NULL;
        temp->data = data;
        temp->bf = 1;
        if (root == NULL)
            root = temp;

        return temp;
    }
    avl_node *insert_node(avl_node *root1, int data)
    {
        
        if (root1 == NULL)
            return new_node(data);

        else if (data < root1->data)
        {
            
            root1->left = insert_node(root1->left, data);
        }

        else if (data > root1->data)
        {
            
            root1->right = insert_node(root1->right, data);
        }

        else
            return root1;

        root1->bf = 1 + max(height(root1->left), height(root1->right));
        
        int check = baalance_factor(root1);
        
        //left to left
        if (check > 1 && root1->left->data > data)
            return right_rotate(root1);

        //left to right
        if(check > 1 && root1->left->data < data)
        {
            root1->left = left_rotate(root1->left);
            return right_rotate(root1);
        }

        //right to right
        if (check < -1 && data > root1->right->data)
            return left_rotate(root1);

        //right to left
        if (check < -1 && data < root1->right->data)
        {
            root1->right = right_rotate(root1->right);
            return left_rotate(root1);
        }

       
        return root1;
    }
    avl_node *right_rotate(avl_node *current)
    {
       
        avl_node *temp = current->left;
        avl_node *temp2 = temp->right;

        temp->right = current;
        current->left = temp2;

        current->bf = max(height(current->left), height(current->right)) + 1;
        temp->bf = max(height(temp->left), height(temp->right)) + 1;
        // root temp
        return temp;
    }

    avl_node *left_rotate(avl_node *current)
    {
        
        avl_node *temp = current->right;
       avl_node *temp2 = temp->left;

        temp->left = current;
        current->right = temp2;

        current->bf = max(height(current->left), height(current->right)) + 1;
        
        temp->bf = max(height(temp->left), height(temp->right)) + 1;
        

     
        // root temp
        return temp;
    }
    /*
    bool breadthfirstsearch(avl_node* temp,int data)
    {
        if(temp==NULL)
        return false;
        queue obj;
        obj.en_queue(temp);
        while(obj.is_empty()!=true)
        {
           
            node* current=obj.de_queue();
            if(current->in->data==data)
            return true;
            if(current->in->left!=NULL)
            {
                obj.en_queue(current->in->left);
            }
            if(current->in->right!=NULL)
            {
                obj.en_queue(current->in->right);
            }

        }
        return false;

    }*/
int BFS(int d, avl_node *temp, queue &q){
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
};
int main()
{
    avl_tree b1;
    avl_node *current = NULL;
    int num,data;
    cout << "Enter Num Of Node To Enter " << endl;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter Data " << endl;
        cin>>data;
        current=b1.insert_node(current,data);

            
    }
    cout<<endl<<endl;
    queue q;
    q.en_queue(current->data);
    cout<<"Search 60 In Tree "<<endl;
    if(b1.BFS(60,current,q)==60)
    cout<<"YES Present In Tree";
    else
    {
        cout<<"NOt Present In Tree";
    }
    
            
}
