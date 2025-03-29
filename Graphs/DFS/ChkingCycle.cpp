#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back

const int N=1e3+10;

vector<ll> g[N];
int vis[N];

bool chkCycle(ll v, ll par=-1){
    vis[v]=1;
    bool isloopexists=false;
    for(auto &child:g[v]){
        if(child==par){
            continue;
        }
        if(vis[child]){
            return true; // agar ek bhi node ne true return 
            // kiya to aage chk krne ki need nhi h
        }
        isloopexists|=chkCycle(child,v);
    }
    return isloopexists;
}

int main() {
    ll n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        ll v1,v2;cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    return 0;
}