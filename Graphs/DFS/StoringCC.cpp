#include <iostream>
#include <vector>
#define vll vector<long long>
using namespace std;

const int N=1e3+10;

vector<int> graph[N];
int visited[N];
vector<vll> cc;
vll curr_cc;

void dfs(int v){
    visited[v]=1;
    curr_cc.push_back(v);
    for(auto &child:graph[v]){
        if(visited[child]){
            continue;
        }
        dfs(child);
    }
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // counting no. of connected comps.
    int ct=0;
    for(int i=1;i<=n;i++){
        if(visited[i]){
            continue;
        }
        curr_cc.clear();
        dfs(i);
        cc.push_back(curr_cc);
        ct++;
    }
    return 0;
}
