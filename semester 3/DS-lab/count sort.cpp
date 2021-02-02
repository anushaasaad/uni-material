#include <iostream>
using namespace std;
int Max(int *a, int n){
	int max=a[0];
	for(int i=0; i<n; i++){
		if(max<a[i]){
			max=a[i];
		}
		
	}
	return max;
}
void countsort(int *a,int n, int max){
	int count[max+1]={0};
	int output[n];
	for(int i=0; i<n; i++){
		count[a[i]]++;
	}
	for(int i=1; i<=max; i++){
		count[i]+=count[i-1];
	}
	for(int i=n-1; i>=0; i--){
		output[--count[a[i]]]=a[i];
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		cout<<output[i] <<" ";
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	countsort(a,n,Max(a,n));
	cout<<endl;

}
