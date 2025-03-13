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

// this function has O(n) TC and O(n) SC
void insert_At_Bottom(stack<int> &stk,int val){
    if(stk.empty()){
        stk.push(val);
        return;
    }

    int num = stk.top();
    stk.pop();

    insert_At_Bottom(stk,val);

    stk.push(num);
}

// this function has O(n^2) TC and O(n) SC
void rev(stack<int> &stk){
    if(stk.empty()) return;

    ll top = stk.top();
    stk.pop();

    rev(stk);
    insert_At_Bottom(stk,top);
}

int main() {
    fastio();
    return 0;
}