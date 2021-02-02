#include <iostream>
using namespace std;
int partition(int *a,int n, int l, int r){
	int pivot=a[0];
	int start=l;
	int end=r;
	while(start<end){
		while(a[start]<=pivot){
			start++;
		}
		while(a[end>pivot]){
			end--;
		}
		if(start<end){
			int temp=a[l];
			a[l]=a[end];
			a[end]=temp;
		}
	}
	return end;
}
void quicksort(int *a,int n, int l, int r){
	if(l<r){
		int loc=partition(a,n,l,r);
		quicksort(a,n,l,loc-1);
		quicksort(a,n,loc+1,r);
		
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	quicksort(a,n,a[0],a[n-1]);
	for(int i=0; i<n;i++){
		cout<<a[i] <<" ";
	}
}
