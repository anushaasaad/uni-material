#include "Q1.cpp"
using namespace std; 
int main()
{
    ODSA obj(4);
	obj.insert(1);
	obj.insert(7);
	obj.search(6);
	obj.display();
	UDSA obj2(5); 
	obj2.insert(0,7);
	obj2.insert(1,3);
	obj2.search(7);
	obj2.display();
}
