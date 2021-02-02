#include<iostream>
using namespace std;
void print(int n, int *a){
	for(int i=0; i<n; i++){
		cout<<a[i] <<" ";
	}
}
void swap(int *a, int *b){
    int *temp;
    *temp=*a;
    *a=*b;
    *b=*temp;
    
}
void bubblesort(int n, int *a){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
      
  }
    cout<<"bubblesort:" <<endl;
    print(n,a);
}
void selectionsort(int n, int *a){
    for (int i = 0; i < n; i++)
    {
        int min=i;
        for (int j = i+1; j < n; j++)
        {
            if(a[i]>a[j]){
               min=j;
            }
        }
        swap(a[min],a[i]);
    }    
    cout<<"\nselectionsort:" <<endl;
    print(n,a);
}
void insertion(int n, int *a){
	int temp;  
    for (int i = 1; i < n; i++) 
    {  
        temp=a[i];  
        int j = i - 1;  
        while (j>=0 && a[j]>temp) 
        {  
            a[j + 1] = a[j];  
            j=j-1;  
        }  
        a[j+1]=temp;  
    }
    print(n,a);
}
int main(){
    int n;
    cout<<"enter size:" <<endl;
    cin>>n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter element [" <<i <<"]:" <<endl;
        cin>>a[i];
    }
    bubblesort(n,a);
    selectionsort(n,a);
    insertion(n,a);
}
