#include<iostream>
#include<fstream>
using namespace std;
int target_value(int a[10], int value, int i,int sum){
	int j=0;
	    if(a[i]==value){
	    	return 1;
		}
		if(i>=0){
			if(a[i]>value){
				target_value(a,value,i-1,sum);
			}else{
				sum=value-a[i];
				if(sum==0){
					return 1;
				}else{
					for(int j=0; j<i; j++){
						sum-=a[j];
						if(sum==0){
							return 1;
							}else{
								target_value(a,value,i-1,0);
							}
						}
						//target_value(a,value,i-1,0);
					}
					target_value(a,value,i-1,0);
				}
				target_value(a,value,i-1,0);
		}
		//target_value(a,value,i-1,0);
}
int main(){
	int a[9]={7,8,6,7,5,3,10,9,15};
	int i=9;
	int t;
	ofstream myfile("Q3input.txt", ios::out);
	cout<<"Enter Target value: " <<endl;
	cin>>t;
	myfile<<t;
	myfile.close();
	ofstream out("Q3output.txt",ios::out);
	if(target_value(a,t,i-1,0)==0){
		out<<"NO";
		cout<<"NO" <<endl;
	}else{
		out<<"YES";
		cout<<"YES" <<endl;
	}
	out.close();
}
