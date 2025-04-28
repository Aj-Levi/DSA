#include<iostream>
#include<vector>
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

class Solution
{
private:
    pair<bool, int> chkBalanced(TreeNode *root)
    {
        if (!root)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = chkBalanced(root->left);
        pair<bool, int> right = chkBalanced(root->right);

        // checking left and right subtrees to be balanced
        // to make the effect/ans of a subtree prpagate 
        // to the root.
        // That's why we don't have to return something like 
        // curr ans & nextfuncCall()
        
        bool condition1 = left.first;  // left subtree balanced
        bool condition2 = right.first; // right subtree balanced

        bool condition3 = abs(left.second - right.second) <= 1; // current subtree balanced

        pair<bool, int> ans;
        ans.first = condition1 && condition2 && condition3;
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return chkBalanced(root).first;
    }
};