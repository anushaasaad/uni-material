#include <iostream>
#include <vector>
#include <fstream> 
using namespace std;
class palindrome{
	int size, arr[];
	public:
		palindrome(int size, int *arr){
			this->size=size;
			for(int i=0; i<size; i++){
				this->arr[i]=arr[i];
				}
		}
		void push_num(int n,int a[], int i, std::vector<int> d){
			ofstream out("Q2output.txt", ios::out);
			//ofstream myfile;//
			//myfile.open("Q2output.txt", ios::out | ios::in);//
			if(i<0){
				return;
			}
			if(a[i]>10){
	    		int digit = a[i]%10;
        		//cout << "digit: " << digit << endl;
	    		a[i] /= 10;
	    		d.push_back(digit);
	    		push_num(n,a,i,d);
			}else{
				d.push_back(a[i]);
				push_num(n,a,i-1,d);
				}
			int in= d.size();
			//ofstream out("Q2output.txt", ios::out);
			for(int z=0; z<=(in/2)-1; z++){
				if(d[z]==d[in-1-z]){
				    if(z==(in/2)-1){
				    	out<<"yes" ;
				        cout<< "yes"<< endl;
						exit(1);
					}
				}else{
					out<<"NO";
					cout << "no";
				    exit(1);
				}
				out.close();
			}
		}
		
};
int main()
{
	int n, a[10],in=0;
	ofstream myfile;
	myfile.open("Q2input.txt", ios::out | ios::in);
	cout<<"enter size of an array:" <<endl;
	cin>>n;
	myfile<<n;
	myfile<<"\nARRAY:\n";
	for(int i=0; i<n; i++){
		cout<<"Enter element " <<i <<": ";
		cin>>a[i];
		myfile<<a[i] <<" ";
}
	myfile.close();
	palindrome p(n,a);
	std::vector<int> d;
	p.push_num(n,a,n-1, d);
}
