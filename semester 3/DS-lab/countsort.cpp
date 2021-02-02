#include <iostream>
using namespace std;
int max(int *a, int n){
	int max=a[0];
	for(int i=0; i<n; i++)
	{
		if(a[i]>max){
			max = a[i];
		}
	}
	cout<<max;
}
void countsort(int *a, int n, int max){
	int count[max]={0};
	int output[n]={0};
	for(int i=0; i<n; i++){
		count[a[i]]++;
	}
	for(int i=1; i<max; i++){
		count[i]=count[i]+count[i-1];
	}
	for(int i=n-1; i>=0; i--){
		output[count[a[i]]--]=a[i];
	}
	for(int i=0; i<n; i++){
		cout<<output[i] <<" ";
	}
}
int main()
{
	int n;
	cin >>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int m=max(a,n);
	countsort(a,n,m);
}
