//ques -> https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include<iostream>
#include<vector>
#include<map>
#include<set>
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

class Solution{
public:
    vector<vector<int> > verticalTraversal(TreeNode *root){
        vector<vector<int> >ans;
        if(!root) return ans;

        map<int,map<int,multiset<int> > > nodes;
        queue<pair<TreeNode *,pair<int,int> > > q;

        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()) {
            pair<TreeNode *,pair<int,int> > temp = q.front();
            q.pop();
            TreeNode *frontNode = temp.first;
            int col = temp.second.first;
            int row = temp.second.second;

            nodes[col][row].insert(frontNode->val);

            if(frontNode->left) {
                q.push(make_pair(frontNode->left,make_pair(col-1,row+1)));
            }
            if(frontNode->right) {
                q.push(make_pair(frontNode->right,make_pair(col+1,row+1)));
            }
        }

        for(auto &colpr: nodes) {
            vector<int> temp;
            for(auto &rowpr: colpr.second) {
                for(auto &val: rowpr.second) {
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};