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

node *buildTree() {
    int data;cin>>data;
    if(data==-1) return NULL;

    node *temp = new node(data);
    temp->left = buildTree();
    temp->right = buildTree();
    return temp;
}

void LevelOrder(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *curr = q.front();
        q.pop();
        if(curr==NULL) {
            cout<<endl;
            if(!q.empty()) q.push(NULL);
            continue;
        }
        cout<<curr->data<<" ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }cout<<endl;
}

void Inorder(node *node){
    if(node->left) Inorder(node->left);
    cout<<node->data<<' ';
    if(node->right) Inorder(node->right);
}
void PreOrder(node *node){
    cout<<node->data<<' ';
    if(node->left) Inorder(node->left);
    if(node->right) Inorder(node->right);
}
void PostOrder(node *node){
    if(node->left) Inorder(node->left);
    if(node->right) Inorder(node->right);
    cout<<node->data<<' ';
} 

int main(){
    node * root = NULL;
    root = buildTree();
    Inorder(root);                                                                                           
    return 0;
}