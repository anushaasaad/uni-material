#include<iostream>
using namespace std;
class stack
{
   	char a[10];
	int n=10;
	int top=-1;
	public:
    void push(char data){
			top++;
			a[top]=data;
		}
	char pop(){
		if(top<0){
				return 0;
			}else{
				return a[top--];
		}
	}
	char peek(){
			return a[top];
		}
	bool isfull(){
		if(top==n-1){
				return true;
			}else{
				return false;
			}
		}
	bool isempty(){
		if(top<0)
				{
					return true;
		}else{
				return false;
			}
		}
};
void check(stack &obj)
{
    int x=0; 
    char str; 
    int k=obj.peek(); 
    for (int i=0; i<k; i++)
    {
        str=obj.pop(); 
        if(str=='{' || str=='(' || str=='[')
        {
          x++;    
        }
        if(str=='}' || str==')' || str== ']')
        {
            x--;
        }
    }
    if(x==0)
    {
        cout<< "matched"; 
    }
    else
    {
        cout<<"Unmatched"; 
    }
}
int main()
{
	int len; 
   stack s;
   char c; 
   cout << "enter length of your string:" << endl; 
   cin >> len; 
   cout << "Enter string characters:" << endl; 
   for(int i=0;i<len;i++)
   {
       cin >> c;  
       s.push(c); 
   }
   check(s); 
}
