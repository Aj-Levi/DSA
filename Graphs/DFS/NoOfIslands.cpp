#include<iostream>
#include<vector>
using namespace std;

pair<int,int> mov[4]={{1,0},{-1,0},{0,1},{0,-1}};

class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }

    void solve(vector<vector<char> >& grid,int i,int j,vector<vector<int> >&vis){
        vis[i][j]=1;
        for(auto &movm: mov){
            int destx=i+movm.first,desty=j+movm.second;
            if(!isValid(destx,desty,grid.size(),grid[0].size())) continue;
            if(vis[destx][desty] || grid[destx][desty]=='0') continue;
            solve(grid,destx,desty,vis);
        }
    }

    int numIslands(vector<vector<char> >& grid) {
        int ct=0;
        vector<vector<int> >vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j] || grid[i][j]=='0') continue;
                ct++;
                solve(grid,i,j,vis);
            }
        }
        return ct;
    }
};