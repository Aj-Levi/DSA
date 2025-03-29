#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

const int N=1e3+10;

vector<ll> graph[N];
int visited[N];

// TC -> O(V + 2*E)
// SC -> O(V) size of the vis array
void dfs(ll v){
    visited[v]=1; // after entering the vertex mark it as vis.
    for(auto &child:graph[v]){
        // before entering the child chk wether vis
        if(visited[child]){
            continue;
        }
        dfs(child);
    }
}

int main(){
    ll n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        ll v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // counting no. of connected comps.
    ll ct=0;
    for(int i=1;i<=n;i++){
        if(visited[i]){
            continue;
        }
        dfs(i);
        ct++;
    }
    cout<<"no. of connected comp.s : "<<ct<<endl;
    return 0;
}
