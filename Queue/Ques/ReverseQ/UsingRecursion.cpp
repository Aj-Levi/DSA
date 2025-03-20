#include <iostream>
#include <queue>
using namespace std;

// O(n) time O(1) space 

void rev(queue<int> &q){
    if(q.empty()) return;

    int temp=q.front();
    q.pop();
    rev(q);
    q.push(temp);
}
