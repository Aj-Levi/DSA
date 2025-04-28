#include<iostream>
#include<vector>
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
    public:
      // Function to return the diameter of a Binary Tree.
      
      // returns <dia,height>
      pair<int,int> diameterFast(Node* root) {
          //base case
          if(root == NULL) {
              pair<int,int> p = make_pair(0,0);
              return p;
          }
          
          pair<int,int> left = diameterFast(root->left);
          pair<int,int> right = diameterFast(root->right);
          
          // dia of left subtree
          int op1 = left.first;

          // dia of right subtree
          int op2 = right.first;

          // dia from both subtree
          int op3 = left.second + right.second + 1;
          
          pair<int,int> ans;
          ans.first = max(op1, max(op2, op3));;
          ans.second = max(left.second , right.second) + 1;
  
          return ans;
      }
      int diameter(Node* root) {
          return diameterFast(root).first;
      }
  };