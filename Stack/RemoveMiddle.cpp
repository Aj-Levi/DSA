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

void RemoveMiddle(stack<int> &stk,int count, int size){
    if(count == size/2){
        stk.pop();
        return;
    }
    int num = stk.top();
    stk.pop();
    RemoveMiddle(stk,++count,size);
    stk.push(num);
}

int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    RemoveMiddle(stk,0,5);
    
    while(!stk.empty()){
        cout<<stk.top()<<' ';
        stk.pop();
    }
}