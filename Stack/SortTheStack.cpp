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

void ins_in_sorted_position(stack<int> &stk, int val){
    if(stk.empty() || val<=stk.top()){
        stk.push(val);
        return;
    }

    int top = stk.top();
    stk.pop();

    ins_in_sorted_position(stk,val);

    stk.push(top);
}

// O(n) TC and O(n) SC
void sort(stack<int> &stk){
    if(stk.empty()) return;

    int top = stk.top();
    stk.pop();

    sort(stk);

    ins_in_sorted_position(stk,top);
}

int main(){
    fastio();
    return 0;
}