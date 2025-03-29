#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define rep(i,n) for(int i=0;i<n;i++)

const int N=1e3+10;
vll g[N]; // SC (V + 2*E)

int main() {
    ll n,m;cin>>n>>m;
    rep(i,m){
        ll u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    return 0;
}
