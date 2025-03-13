#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <iomanip>
#include <ios>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <numeric>
#include <unordered_map>
using namespace std;
#define ll long long
#define fastio() \
ios_base::sync_with_stdio(false); \
cin.tie(nullptr)

ll mx_size = 100;

class Mystack{
    public:
    ll top;
    ll *arr;
    ll size;

    Mystack(){
        this->top=-1;
        this->arr=new ll[mx_size];
        this->size=mx_size;
    }

    void push(Mystack* stk, ll x){
        if(stk->top == (stk->size)-1){
            cout<<"overflow"<<endl;
            return;
        }
        (stk->top)++;
        stk->arr[stk->top] = x;
    }

    void pop(Mystack* stk){
        if(stk->top == -1){
            cout<<"underflow"<<endl;
            return;
        }
        stk->arr[stk->top] = 0;
        (stk->top)--;
    }

    ll top(Mystack* stk){
        if(stk->top == -1){
            cout<<"stack is empty"<<endl;
            return;
        }
        return stk->arr[stk->top];
    }
    
    string isempty(Mystack* stk){
        return stk->top == -1?"yes":"no";
    }
};

void solve() {
    Mystack* stk = new Mystack();
    return;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}