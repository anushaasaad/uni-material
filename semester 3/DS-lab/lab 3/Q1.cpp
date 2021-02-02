#include "Q1.h"
#include <iostream>
#include<fstream>
#include <stdio.h>
#include <string>
#include<cstdlib> 
using namespace std; 
DSA::DSA()
{
	cout<<"enter size of dynamic array: \n";
		cin>>size;
		data=new int[size];
		for(int i=0;i<size;i++)
		{
			data[i]=i;
		}
}
void DSA::display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<data[i]<<endl;
		}
	}	
DSA::~DSA()
{
    if(data !=0)
    {
        cout<<"Array destroyed"<<endl;
        delete [] data;
        data=0;
        size=0; 
    }
}
void DSA::insert(int index, int value)
{	
	if(index<0 || index>=size)
	{
		cout<<"index is out of bounds\n";
		exit(0);
	}
	*(data+index)=value;
}
void DSA::search(int value)
	{
		int flag=0;
		for(int i=0;i<size;i++)
		{
			if(*(data+i)==value)
			cout<<"Found at index: "<<i<<"\n";
			flag=1;
		}
		if(flag==0)
		cout<<"Entry not found\n";
    }
    ODSA::ODSA(int n)
	{
        size=n ;
        data= new int[size]; 
	}
	void ODSA::insert(int value)
	{
		int temp;
		data[size-1]=value;
		for(int i=0;i<size;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(data[i]==data[j])
				{
					continue;
				}
				if(data[i]>data[j])
				{
					temp=data[i];
					data[i]=data[j];
					data[j]=temp;
				}
			}
		}
	}
	void ODSA::search(int value)
	{
		int flag=0;
		for(int i=0;i<size;i++)
		{
			if(*(data+i)==value)
			cout<<"Found at index: "<<i<<"\n";
			flag=1;
		}
		if(flag==0)
		cout<<"Entry not found\n";
    }
    UDSA::UDSA(int n)
	{
        size=n ;
        data= new int[size]; 
	}
	void UDSA::insert(int index, int value)
	{	
		if(index<0 || index>=size)
		{
			cout<<"index is out of bounds\n";
			exit(0);
		}
		data[index]=value;
	}
	void UDSA::search(int val)
	{
		int flag=0;
		for(int i=0;i<size;i++)
		{
			if(*(data+i)==val)
			cout<<"Found at index: "<<i<<"\n";
			flag=1;
		}
		if(flag==0)
		cout<<"Entry not found\n";
    }	
