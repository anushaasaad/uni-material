#ifndef QUES_H
#define QUES_H
using namespace std; 
class DSA
{
    protected:
    int size;
    int *data;
    public:
    DSA();
    ~DSA();
    void display();
    virtual void insert (int index, int value); 
    virtual void search(int value); 

};

class ODSA: public DSA
{
	public:
    ODSA(int n);
    void insert(int value); 
    void search(int value);  
};
class UDSA: public DSA
{
	public:
    UDSA(int n); 
    void insert(int index, int value); 
    void search(int value); 
};
#endif
