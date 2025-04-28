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
    private:
        pair<bool,int> chkSumTree(Node *node){
            if(!node) {
                pair<bool,int> p = make_pair(true,0);
                return p;
            }

            if(!node->left && !node->right) {
                pair<bool,int> p = make_pair(true,node->data);
                return p; 
            }

            pair<bool,int> left = chkSumTree(node->left);
            pair<bool,int> right = chkSumTree(node->right);

            return make_pair((node->data == (left.second + right.second)) && left.first && right.first , left.second + right.second + node->data);
        }
    public:
      bool isSumTree(Node* root) {
        return chkSumTree(root).first;
      }
  };