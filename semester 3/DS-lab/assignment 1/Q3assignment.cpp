#include<iostream>
#include <stdlib.h>
#include<conio.h>
#include <fstream>
using namespace std;
//int arr[5]={12,23,7,6,9};
//static int k=0;
bool starting(int arr[] , int pos, int sum, int temp, int size)
        {	
            //Base Case.
            if (sum == temp)
                {return true;}
                
	          for (int i = pos; i < size; i++)//Increamenting ith Position.
	            {
	             if (temp + arr[i] <= sum)
	               {
//	               	cout<<temp<<" "<<i<<endl;
	                  temp += arr[i];//Adding the current ith Value to Temp     
	                  bool f=starting(arr, i + 1, sum, temp, size);//incrementing the ith value till it satisfies the equation
	                  if(f){
	                  	return true;
					  }
	                  temp -= arr[i]; //Substracting the same ith value to Delete the current value from the Temp.
	                }
	            }
         return false;
        }
int main(){
	int arr[7]={11,6,7,5,1,13,12};
    // int n;
    // cin>>n;
    ofstream myfile("Q3input.txt", ios::out);
    int target;
    cout<<"Your target value:"<<endl;
    cin>>target;
    myfile<<target;
    myfile.close();
    ofstream out("Q3output.txt",ios::out);
    if(starting(arr,0,target,0,5)==1){
    	cout<<"yes";
    	out<<"NO";
	}else{
		out<<"no";
		cout<<"no";
	}
    out.close();


}
