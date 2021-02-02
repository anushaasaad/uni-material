#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int gap;
	for(gap=n/2; gap>0; gap/=2){
		for(int j=gap; j<n; j++){
			//int temp = a[j]; 
			for(int i=j-gap; i>=0; i-=gap){
				if(a[i+gap]>a[i]){
					int temp=a[i+gap];
					a[i+gap] = a[i]; 
					a[i]=temp;
				}
			}
		}
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i] <<" ";
	}
}
