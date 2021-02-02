#include <iostream>
#include <string>
using namespace std;
class And{
    int bit;
    public:
    And(int bit){
        this->bit=bit;
    }
    void operator && (And& a){
        int x;

        if(bit==0 && a.bit==0){
            x=0;
        }else
        if(bit==0 && a.bit==1){
            x=0;
        }else
        if(bit==1 && a.bit==0){
            x=0;
        }else
        if(bit==1 && a.bit==1){
            x=1;
        }
        if(x==0){
            cout<<"the output is low." <<endl;

        }else
        if(x==1){
            cout<<"the output is high." <<endl;
        }else{
            cout<<"invalid input." <<endl;
        }
    }

};
int main()
{
    int a,b;
    cout<<"enter bit1: " <<endl;
    cin>>a;
    And a1(a);
    cout<<"enter bit21: " <<endl;
    cin>>b;
    And a2(b);
    a1&&a2;

}
