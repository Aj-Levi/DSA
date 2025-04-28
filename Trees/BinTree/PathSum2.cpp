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
private:
    void StorePaths(TreeNode *node, int sum,int targetsum, vector<int> curr_path, vector<vector<int> >&ans) {
        if(!node) return;

        sum+=node->val;
        curr_path.push_back(node->val);

        if(!node->left && !node->right) {
            if(sum == targetsum) {
                ans.push_back(curr_path);
            }
            return;
        }

        if(node->left) StorePaths(node->left, sum, targetsum, curr_path, ans);
        if(node->right) StorePaths(node->right, sum, targetsum, curr_path, ans);
    }
public:
    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> curr_path;
        vector<vector<int> > ans;

        if(root==NULL) return ans;

        StorePaths(root,sum,targetSum,curr_path,ans);

        return ans;
    }
};