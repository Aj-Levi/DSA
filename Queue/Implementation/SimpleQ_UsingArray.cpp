#include <iostream>
using namespace std;

// round Robin fashion is not allowed

int mx_size=1000;

class Q{
    int *arr;
    int f;
    int r;

    public:
    Q(){
        arr=new int[mx_size];
        f=-1;
        r=0;
    }

    void nQ(int data){
        if(r==mx_size) cout<<"Overflow"<<endl;
        else{
            arr[r]=data;
            r++;
        }
    }

    int dQ(){
        if(f==r){
            cout<<"Underflow"<<endl;
            return -1;
        }else{
            int temp=arr[f];
            arr[f]=-1;
            f++;
            if(f==r) f=-1,r=0;
            return temp;
        }
    }
};