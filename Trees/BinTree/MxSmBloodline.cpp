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

class Solution
{
public:
    
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
        //base case
        if( root == NULL ) {
            
            if(len > maxLen) 
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen) 
            {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);

    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};