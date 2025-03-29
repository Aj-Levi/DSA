#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// https://leetcode.com/problems/island-perimeter/

pair<int,int> mov[4]={{1,0},{-1,0},{0,1},{0,-1}};

class Solution {
    public:
    bool isValid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    void solve(vector<vector<int> >& grid,int i,int j,int &ans,vector<vector<int> > &vis){
        vis[i][j]=1;
        int ct=0;
        for(auto &movm: mov){
            int destx=i+movm.first,desty=j+movm.second;
            if(isValid(destx,desty,grid.size(),grid[0].size())){
                if(grid[destx][desty]==1){
                    ct++;
                    if(!vis[destx][desty]) solve(grid,destx,desty,ans,vis);
                }
            }
        }
        ans+=(4-ct);
    }

    int islandPerimeter(vector<vector<int> >& grid) {
        int ans=0;
        int sr=0,sc=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    sr=i;sc=j;
                }
            }
        }
        vector<vector<int> > vis(grid.size(),vector(grid[0].size(),0));
        solve(grid,sr,sc,ans,vis);
        return ans;
    }
};