#include<iostream>
#include<vector>
#include<map>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;

// very nice app for finding LCA in O(n) time and O(height) space.

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
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node == NULL) return NULL;
        if(node==p || node==q) return node;

        TreeNode *leftAns = lowestCommonAncestor(node->left,p,q);
        TreeNode *rightAns = lowestCommonAncestor(node->right,p,q);

        if(leftAns && rightAns) return node;
        else if(leftAns && !rightAns) return leftAns;
        else if(rightAns && !leftAns) return rightAns;
        else return NULL;
    }
};