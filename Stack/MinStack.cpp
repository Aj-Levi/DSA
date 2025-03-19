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
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define fastio() \
ios_base::sync_with_stdio(false); \
cin.tie(nullptr)

// getmin works in O(1) time
// but the constructed data structure takes O(2n) space
// ~ Striver 

class Special_Stack{

    stack<pair<int,int> > s;

    public:

    void push(int data){
        // for first element
        if(s.empty()) s.push(mp(data,data));
        else s.push(mp(data,min(data,s.top().second)));
    }

    int pop(){
        // Underflow
        if(s.empty()) return -1;
        else{
            int temp=s.top().first;
            s.pop();
            return temp;
        }
    }

    int top(){
        // Underflow
        if(s.empty()) return -1;
        else return s.top().first;
    }

    int getmin(){
        // Underflow
        if(s.empty()) return -1;
        else return s.top().second;
    }
};

// getmin works in O(1) time
// and the constructed data structure takes O(n) space :)

class SpecialStack {

	stack<int> s;
    int mini = INT_MAX;

    public:

    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }else {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }else{
                s.push(data);
            }
        }
    }

    int pop() {
        // Underflow
        if(s.empty()) return -1;
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        // Empty Stack
        if(s.empty()) return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }else{
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()) return -1;
        
        return mini;
    }  
};