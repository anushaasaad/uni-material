#include <iostream>
#include <cstdlib>
#include<string.h>
using namespace std;
class safearray{
    int ncol;
    int *darray;
    public:
    safearray(){
        ncol=0;
        darray=NULL;
    }
    safearray(int ncol){
        this->ncol=ncol;
        darray=new int[ncol];
    }
    ~safearray(){
        delete [] darray;
        darray=NULL;
    }
    void fillarray(){
        for (int i = 0; i < ncol; i++)
        {
            int x;
            cin>>x;
            darray[i]=x;
        }
        
    }
    //bounds check
    int &operator [](int i){
        if (i<0 && i>ncol-1)
        {
            cout<<"array out of bounds." <<endl;
            exit(1);
        }else{
            return darray[i];
        }
        
    }
    safearray (const safearray& obj){
        ncol=obj.ncol;
        darray=new int[ncol];
        memcpy(darray,obj.darray, sizeof(int)*ncol);
    }
    safearray& operator=(const safearray& obj){
        if(this==&obj){
            return *this;
        }
        delete [] darray;
        darray=NULL;
        ncol=obj.ncol;
        darray= new int[ncol];
        memcpy(darray,obj.darray,sizeof(ncol));
    }
    safearray& operator!=(const safearray& obj){
        for (int i = 0; i < ncol; i++)
        {
            if(darray[i]!=obj.darray[i]){
                cout<<"not equal" <<endl;
            }
        }
    }
    void insert(int i,int value){
        if(i<0 && i>=ncol){
            cout<<"out of bounds" <<endl;
            exit(1);
        }
        *(darray+i)=value;
    }
    void search(int value){
        for (int i = 0; i < ncol; i++)
        {
            if(darray[i]==value){
                cout<<"value found at index: " <<i <<endl;
            }
        }
    }
    void insert_sorted(int i, int value){
        int temp;
        if (i<0 && i>=ncol)
        {
            cout<<"out of bounds" <<endl;
        }else{
            darray[i]=value;
            for(int i = 0; i < ncol; i++)
            {
                for (int j = 0; j < ncol-1; j++)
                {
                    if(darray[j]>darray[j+1]){
                        temp=darray[j];
                        darray[j]=darray[j+1];
                        darray[j+1]=temp;
                    }
                }
                
            }
            
        }
        
    }
};
int main(){
    int columns;
      
      cout<<"enter cols"<<endl;
      cin>>columns;
      safearray ob1(columns);
      
      ob1.fillarray();   
      safearray ob2=ob1;
      safearray ob3;
      
      ob3=ob1;
      cout << ob1[1] << endl;
      cout<<ob2[2]<<endl;     //checking bounds of array
      cout<<ob3[2];
     ob1.insert(3,44);
     ob1.search(3);
     ob3.insert_sorted(6,22);      
}