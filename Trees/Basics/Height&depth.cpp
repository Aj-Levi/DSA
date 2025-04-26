#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

const int N=1e3+10;

vector<ll> g[N];
int height[N],depth[N];

void dfs(ll v,ll par=-1){
    for(auto &child: g[v]){
        if(child==par) continue;
        depth[child]=depth[v]+1;
        dfs(child,v);
        height[v]=max(height[v],height[child]+1);
    }
}