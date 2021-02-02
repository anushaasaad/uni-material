#include <iostream>
#include <string>
#include <algorithm>
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
			while(s.topp()!='(' && !s.isempty()){
				char temp=s.topp();
				x+=temp;
				s.pop();
			}
			if(s.topp()=='('){
				s.pop();
			}
		} 
		else if(s.isoperator(c[i])==true){
			if(s.isempty()){
				s.push(c[i]);
			}else{
				if(s.precedence(c[i])>s.precedence(s.topp())){
					s.push(c[i]);
				}else while(!s.isempty() && s.precedence(c[i])<=s.precedence(s.topp())){
					char temp=s.topp();
					x+=temp;
					s.pop();
				}
				s.push(c[i]);
			}
		}
	}
	while(!s.isempty()){
		x+=s.topp();
		s.pop();
	}
	return x;
}
string RevStr(string s,int i){
	string x;
	for(i=s.length()-1; i>=0; i--){
		x+=s[i];
	}
}

string infix_to_prefix(string b){
	stack s;
	string x,c;
//	c=RevStr(b,0);
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
			while(s.topp()!='(' && !s.isempty()){
				char temp=s.topp();
				x+=temp;
				s.pop();
			}
			if(s.topp()=='('){
				s.pop();
			}
		}else if(s.isoperator(c[i])==true){
			if(s.isempty()){
				s.push(c[i]);
			}else{
				if(s.precedence(c[i])>=s.precedence(s.topp())){
					s.push(c[i]);
				}else while(!s.isempty() && s.precedence(c[i])<s.precedence(s.topp())){
					char temp=s.topp();
					x+=temp;
					s.pop();
				}
				s.push(c[i]);
			}
		}
		
	}
	while(!s.isempty()){
		x+=s.topp();
		s.pop();
	}
	string a;
//	a=RevStr(x,0);
	reverse(x.begin(),x.end());
	return a;
}
		
int main(){
	int a[10],d;
	int n;
	stack s;
	string x,Post,pre;
	cout<<"enter the expression:" <<endl;
	cin>>x;
	Post=infix_to_postfix(x);
	cout<<Post <<endl;
	pre=infix_to_prefix(x);
	cout<<pre<<endl;
	return 0;
}
