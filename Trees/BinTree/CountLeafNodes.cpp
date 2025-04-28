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

node *buildFromLvlOrder(){
    int data;cin>>data;
    if(data == -1) return NULL;

    node *temp = new node(data);
    queue<node *> q;
    q.push(temp);

    while(!q.empty()){
        node *curr = q.front();
        q.pop();

        int left,right;cin>>left>>right;
        if(left != -1) curr->left = new node(left), q.push(curr->left);
        if(right != -1) curr->right = new node(right), q.push(curr->right);
    }

    return temp;
}

int countLeafNodes(node *root){
    queue<node*>q;
    if(root) q.push(root);

    int ct=0;

    while(!q.empty()){
        node *curr=q.front();
        q.pop();

        if(!curr->left && !curr->right) ct++;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return ct;
}

int main(){
    node * root = NULL;
    root = buildFromLvlOrder();
    cout<<countLeafNodes(root)<<endl;                                                                              
    return 0;
}