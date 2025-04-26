#include<iostream>
#include<vector>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
const int N=1e3+10;

vll g[N];
int parent[N];

void dfs(ll v,ll par=-1){ // O(V + 2*E)
    for(auto &child: g[v]){
        if(child==par) continue;
        parent[child]=v;
        dfs(child,v);
    }
}

vll path(ll v){ // O(V)
    vll temp;
    while(v!=-1){
        temp.pb(v);
        v=parent[v];
    }
    reverse(all(temp));
    return temp;
}

int main(){
    int n,m;cin>>n>>m;
    while(m--){
        ll u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll a,b;cin>>a>>b;
    parent[1]=-1;
    dfs(1);
    vll path_a=path(a),path_b=path(b);
    ll LCA=1;
    for(int i=0;i<min(path_a.size(),path_b.size());i++){
        if(path_a[i]!=path_b[i]) break;
        LCA=path_a[i];
    }
    cout<<LCA<<endl;
    return 0;
}