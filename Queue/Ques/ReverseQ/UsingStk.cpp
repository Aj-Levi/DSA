#include <iostream>
#include <queue>
using namespace std;

// O(n) time O(n) space 

void rev(queue<int> &q){
    stack<int> stk;
    while(!q.empty()){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
}