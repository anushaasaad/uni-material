#ifndef quiz_h
#define quiz_h
using namespace std;
struct node{
	int data;
	node* next;
	node* prev;
};
class linked_list{
	node *head,*tail;
	public:
		linked_list();
		void add_node(int x);
		node* get_head();
	//	void reverse();
		void display();
		void search(int a, int b);
//		void insert_head(int x);
//		void removeduplicates();
//		void deletefromend();
};
#endif
