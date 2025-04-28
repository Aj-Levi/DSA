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

bool chkSame(node *node1, node *node2) {
    if(node1==NULL && node2==NULL) return true;

    if(node1==NULL && node2!=NULL) return false;
    if(node2==NULL && node1!=NULL) return false;
    
    return (node1->data == node2->data) && chkSame(node1->left, node2->left) && chkSame(node1->right,node2->right);
}