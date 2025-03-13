#include<bits/stdc++.h>
using namespace std;

class B{
    public:
    int a,b;
    void operator+(B obj){
        int val1=this->a;
        int val2=obj.b;
        cout<<val1-val2<<endl;
    }

    void operator++(){
        int val=this->a;
        val+=2;
        this->a=val;
        cout<<this->a<<endl;
    }
};

int main(){
    B obj,obj1;
    obj.a=7;
    obj1.a=1;
    obj1.b=2;
    //obj1+obj1;
    ++obj;
}