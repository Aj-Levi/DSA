#include<iostream>
#include<vector>
#include<map>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        map<int,int> mp;
        queue<pair<TreeNode *,int> > q;
        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<TreeNode *,int> temp = q.front();
            q.pop();
            TreeNode *frontNode = temp.first;
            int row = temp.second;

            if(mp.find(row) == mp.end()) {
                mp[row] = frontNode->val;
            }

            if(frontNode->right) q.push(make_pair(frontNode->right,row+1)); 
            if(frontNode->left) q.push(make_pair(frontNode->left,row+1)); 
        }

        for(auto &pr: mp){
            ans.push_back(pr.second);
        }
        return ans;
    }
};