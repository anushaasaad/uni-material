#ifndef ques_1
#define ques_1
#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class linked_list{
	private:
      node *head,*tail;
	public:
	linked_list();
	void add_node(int n);
	int count();
	
};
#endif
