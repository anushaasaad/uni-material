   #include <iostream>
using namespace std;
void maxheap(int a[],int n,int i)
{
	int largest=i;
	int l=(i*2)+1;
	int r=(i*2)+2;
	while (l<n && a[l]>a[largest])
	{
		largest=l;
	}
	while (r<n&&a[r]>a[largest])
	{largest=r;}
	if(largest!=i)
	{
		swap(a[largest],a[i]);
		maxheap(a,n,largest);
	}
}
void heapsort(int a[],int n)
{  cout<<"hello";
  for(int i=(n/2)-1;i>=0;i--)
  {
  	maxheap(a,n,i);
  	
	  }	
	  for(int i=n-1;i>=0;i--)
	  {
	  	swap(a[0],a[i]);
	  	maxheap(a,n,0);
	  	
	  }
}
int main()
{   int a[7]={15,20,17,1,30,10,7};
	heapsort(a,7);
	for(int i=6;i>=0;i--)
	cout<<a[i]<<" ";
	cout<<endl;
}
