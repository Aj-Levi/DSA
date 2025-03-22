#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(empty()) return -1;
        else{
            int temp=s1.top();
            s1.pop();
            return temp;
        }
    }
    
    int peek() {
        if(empty()) return -1;
        else return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
}; 