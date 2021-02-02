#include <iostream>
#include<string.h>
using namespace std;
int main()
{
	int i, j , m, n; //m=i= columns n=j=rows
	char str[m][n],b[10];
	cout<<"Enter size of colomns:";
	cin>>m;
	cout<<"\nEnter size of rows:";
	cin>>n;
	for(i=0; i<m;i++){
		for(j=0; j<n; j++){
			cout<<"Enter element[" <<i <<"][" <<j <<"]:";
			cin>>str[i][j];
		}
	}
	for(i=0; i<m; i++){
			cout<<"\n";
		for(j=0; j<n; j++){
			cout<<str[i][j]<<" ";
		}
	}
//	cout<<"\nWord tobe searched: ";
//	cin>>b;
	//string search[b];
	//int score[b];
	
	// input of the word that will be searched
//	for(i=0; i< strlen(b);i++)
//	{
//	    cout<<b[i];
//	}
//	//vertical downward
//	for(i=0, j=0; i<strlen(b) && j<n; j++, i++){
//		int k=0;
//		if(b[i]==str[k][j]){
//			cout<<"yes";
//		}
//	}
}

