#include <iostream>
using namespace std;

// round Robin fashion is allowed and has to be followed

int mx_size=1000;

class Q{
    int *arr;
    int f;
    int r;

    public:
    Q(){
        arr=new int[mx_size];
        f=-1;
        r=-1;
    }

    void nQ(int data){
        if((r==mx_size-1 && f==0) || (r==(f-1))) cout<<"Overflow"<<endl;
        else{
            r=(r+1)%mx_size;
            arr[r]=data;
            if(f==-1) f=0;
        }
    }

    int dQ(){
        if(f==r){
            cout<<"Underflow"<<endl;
            return -1;
        }else{
            int temp=arr[f];
            arr[f]=-1;
            f=(f+1)%mx_size;
            if(f==r) f=-1,r=-1;
            return temp;
        }
    }
};