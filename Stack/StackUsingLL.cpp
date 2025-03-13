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

class node{
    public:
    int data;
    node *next;

    node(int data){
        this->data=data;
    }
};

class Mystack{
    public:
    node* top;

    Mystack(){
        top=NULL;
    }

    void push(ll x){
        node *temp = new node(x);
        if(temp==NULL){
            cout<<"overflow"<<endl;
            return;
        }
        temp->next=this->top;
        this->top=temp;
        cout<<"Pushed Successfully"<<endl;
        return;
    }

    void pop(){
        if(this->top == NULL){
            cout<<"underflow"<<endl;
            return;
        }
        node *dest = this->top->next;
        this->top->next=NULL;
        cout<<"Popped "<<this->top->data<<endl;
        delete this->top;
        this->top = dest;
    }

    ll peek(){
        return this->top->data;
    }

    bool isempty(){
        return this->top == NULL;
    }
};

void solve() {
    Mystack* stk = new Mystack();
    while(true){
        cout << "1. Push\n2. Pop\n3. Top\n4. Check if empty\n5. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                ll val;
                cout << "Enter value to push: ";
                cin >> val;
                stk->push(val);
                break;
            }
            case 2:
                stk->pop();
                break;
            case 3:
                if (!stk->isempty()) {
                    cout << "Top element: " << stk->peek() << endl;
                }
                break;
            case 4:
                cout << (stk->isempty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice\n";
                break;
        }
    }
    return;
}

int main() {
    fastio();
    solve();
    return 0;
}