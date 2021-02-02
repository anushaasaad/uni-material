#include<iostream>
using namespace std;
class MinHeap{
    int *arr;
    int capacity;
    int size;
    public:
    MinHeap(int capacity){
        this->capacity=capacity;
        arr=new int[capacity];
        this->size=0;
    }
    int getsize(){
        return size;
    }
    int getparent(int child){
        if(child%2==0)
            return (child/2)-1;
        else
            return (child/2);
    }
    int getleft(int parent){
        return (2*parent+1);
    }
    int getright(int parent){
        return (2*parent+2);
    }
    int getmax(){
        for(int i=0; i<size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return arr[0];
    }
    bool isleaf(int i){
        if(i>=size)
            return true;
        return false;
    }
    void shiftup(int i){
        if(i==0)
            return;
        int parent_index=getparent(i);
        if(arr[parent_index]>arr[i]){
            int temp = arr[parent_index];
            arr[parent_index]=arr[i];
            arr[i]=temp;
            shiftup(parent_index);
        }
    }
    void shiftdown(int i){
        int l=getleft(i);
        int r=getright(i);
        if(isleaf(l))
            return;
        int minindex=i;
        if(arr[l]<arr[i]){
            minindex=l;
        }
        if(!isleaf(r)&&(arr[r]<arr[minindex])){
            minindex=r;
        }
        if(minindex!=i){
            int temp=arr[i];
            arr[i]=arr[minindex];
            arr[minindex]=temp;
            shiftdown(minindex);
        }
    }
    void insert(int k){
        arr[size]=k;
        shiftup(size);
        size++;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int extractmin(){
        int min=arr[0];
        arr[0]=arr[size-1];
        size--;
        shiftdown(0);
        return min;
    }
    int remove_at(int k){
        int r=arr[k];
        arr[k]=arr[size-1];
        size--;
        int p=getparent(k);
        if(k==0 || arr[k]<arr[p])
            shiftdown(k);
        else
            shiftup(k);
        return r;
    }
    void display(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void heapify(int *array, int len){
        size=len;
        arr=array;
        for(int i=size-1; i>=0; --i){
            shiftdown(i);
        }
    }
};
int main(){
    MinHeap mh(10);
    mh.insert(7);
    mh.insert(5);
    mh.insert(9);
    mh.insert(4);
    mh.insert(3);
    mh.insert(6);
    mh.insert(8);

    mh.remove_at(3);
    cout<<"After Removal: ";
    mh.display();
    cout<<"min: "<<mh.extractmin();

    
}