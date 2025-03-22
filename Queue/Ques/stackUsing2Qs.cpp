#include<iostream>
#include<queue>
using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        if(empty()) return -1;
        else{
            int temp=q1.front();
            q1.pop();
            return temp;
        }
    }
    
    int top() {
        if(empty()) return -1;
        else return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};