#include <iostream>
#include <string.h>
#include <algorithm>
#include <fstream>
using namespace std;
class stack{
	int a[50];
	int n=10;
	int top=-1;
	public:
		int topp(){
			return top;
		}
		void push(int data){
			top++;
			a[top]=data;
		}
		int pop(){
			if(top<0){
				return 0;
			}else{
				return a[top--];
		}
	}
		int peek(){
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
		bool isoperator(char c){
			if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
				return true;
			}
	}
	    int precedence(char c){
	    	if(c=='^'){
	    		return 3;
			}else if(c=='*' || c=='/'){
				return 2;
			}
			else if(c=='+'|| c=='-'){
				return 1;
			}
			else{
				return -1;
			}
		}
		bool ischaracter(char c){
			if(c>='a' && c<='z' ){
				return true;
			}else if(c>='A' && c<='Z'){
				return true;
			}
			return false; 
	}
};
string infix_to_postfix(string c){
	stack s;
	string x;
	int i=0;
	for(int i=0; i<c.length(); i++){
		if(s.ischaracter(c[i])==true){
			x+=c[i];
		}
		else if(c[i]=='('){
			s.push(c[i]);
		}
		else if(c[i]==')'){
			while(s.peek()!='(' && !s.isempty()){
				char temp=s.peek();
				x+=temp;
				s.pop();
			}
			if(s.peek()=='('){
				s.pop();
			}
		} 
		else if(s.isoperator(c[i])==true){
			if(s.isempty()){
				s.push(c[i]);
			}else{
				if(s.precedence(c[i])>s.precedence(s.peek())){
					s.push(c[i]);
				}else if(s.precedence(c[i])==s.precedence(s.peek()) && c[i]=='^'){
					s.push(c[i]);
				}else{
				 while(!s.isempty() && s.precedence(c[i])<=s.precedence(s.peek())){
					char temp=s.peek();
					x+=temp;
					s.pop();
				}
				s.push(c[i]);
			}
		}
	}
	}
	while(!s.isempty()){
		x+=s.peek();
		s.pop();
	}
	return x;
}
string infix_to_prefix(string c){
	stack s;
	string x;
	reverse(c.begin(),c.end());
	int i=0;
	for(int i=0; i<c.length(); i++){
		if(c[i]=='('){
			c[i]=')';
		}else if(c[i]==')'){
				c[i]='(';
			}
	}
	for(int i=0; i<c.length(); i++){
		if(s.ischaracter(c[i])==true){
			x+=c[i];
		}else if(c[i]=='('){
			s.push(c[i]);
		}else if(c[i]==')'){
			while(s.peek()!='(' && !s.isempty()){
				char temp=s.peek();
				x+=temp;
				s.pop();
			}
			if(s.peek()=='('){
				s.pop();
			}
		}else if(s.isoperator(c[i])==true){
			if(s.isempty()){
				s.push(c[i]);
			}else{
				if(s.precedence(c[i])>s.precedence(s.peek())){
					s.push(c[i]);
				}else if(s.precedence(c[i])==s.precedence(s.peek()) && c[i]=='^'){
				//	s.push(c[i]);
					while(!s.isempty() && s.precedence(c[i])==s.precedence(s.peek()) && c[i]=='^'){
					char temp=s.peek();
					x+=temp;
					s.pop();
					}
					s.push(c[i]);
				}else if(s.precedence(c[i])==s.precedence(s.peek())){
					s.push(c[i]);
				}else{
					while(!s.isempty() && s.precedence(c[i])<s.precedence(s.peek())){
						char temp=s.peek();
						x+=temp;
						s.pop();
						}
						s.push(c[i]);
				}
			}
		}
		
	}
	while(!s.isempty()){
		x+=s.peek();
		s.pop();
	}
//	string a;
//	a=RevStr(x,0);
	reverse(x.begin(),x.end());
	return x;
}
		
int main(){
	int a[10],d;
	int n;
	stack s;
	string x,Post,pre;
	ifstream myfile("input001.txt");
	cout<<"enter the expression:" <<endl;
	myfile>>x;
	myfile.close();
	cout<<x <<endl; 
	//cin>>x;
	ofstream file("output001.txt");
	Post=infix_to_postfix(x);
	file<<"post:"<<Post;
	cout<<"post:"<<Post <<endl;
	pre=infix_to_prefix(x);
	file<<"\nprefix: " <<pre; 
	cout<<"pre:"<<pre<<endl;
	return 0;
	file.close();
}

