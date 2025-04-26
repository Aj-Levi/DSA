#include<iostream>
#include<vector>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;

class node{
public:
    int data;
    node *right;
    node *left;

    node(int d){
        data=d;
        right=NULL;
        left=NULL;
    }
};

const int INF = 1e5+10;

vector<vector<int> > LevelOrder(node *root){
    queue<node *> q;
    stack<int> stk;
    q.push(root);
    q.push(NULL);
    stk.push(root->data);
    stk.push(INF);

    while(!q.empty()){
        node *curr = q.front();
        q.pop();
        if(curr==NULL) {
            if(!q.empty()) q.push(NULL),stk.push(INF);
            continue;
        }

        if(curr->right) q.push(curr->right),stk.push(curr->right->data);
        if(curr->left) q.push(curr->left),stk.push(curr->left->data);
    }
    vector<vector<int> >ans;
    vector<int> temp;

    while(!stk.empty()){
        int val = stk.top();
        stk.pop();
        if(val==INF) {
            if(temp.size()) ans.push_back(temp);
            temp.clear();
        }
        else temp.push_back(val);
    }
    if(temp.size()) ans.push_back(temp);
    return ans;
}