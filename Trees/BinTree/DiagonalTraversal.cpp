// ques -> https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

#include<iostream>
#include<vector>
#include<map>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
private:
    void solve(Node *node, map<int,vector<int> > &mp, int row,int col){
        if(node==NULL) return;

        mp[row-col].push_back(node->data);

        if(node->left) solve(node->left,mp,row+1,col-1);
        if(node->right) solve(node->right,mp,row+1,col+1);
    }
public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        map<int,vector<int> > mp;

        solve(root,mp,0,0);

        for(auto &pr: mp){
            for(auto &val: pr.second){
                ans.push_back(val);
            }
        }

        return ans;
    }
};