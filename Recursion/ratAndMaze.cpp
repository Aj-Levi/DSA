#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define fastio() \
ios_base::sync_with_stdio(false); \
cin.tie(nullptr)

inline void py(){
    cout<<"YES"<<endl;
}
inline void pn(){
    cout<<"NO"<<endl;
}
void printvec(vector<ll> &v){
    for(auto &val:v){
        cout<<val<<' ';
    }
    cout<<endl;
}
vector<ll> vin(ll n){
    vector<ll>temp;
    for(int i=0;i<n;i++){
        ll x;cin>>x;temp.push_back(x);
    }
    return temp;
}
const int N=1e3+10;
int n;
int a[N][N];
int vis[N][N];
vector<string> v;

bool isvalid(ll i,ll j){
    return (((i>=0) && (i<n) && (j>=0) && (j<n))&&(a[i][j]==1)&&(!vis[i][j]));
}

void bfs(string &s,ll sr,ll sc){
    vis[sr][sc]=1;
    if(sr==n-1 && sc==n-1){
        v.push_back(s);
        return;
    }
    if(isvalid(sr+1,sc)){
        s.push_back('D');bfs(s,sr+1,sc);vis[sr+1][sc]=0;
        if(!s.empty()) s.pop_back();
    }
    if(isvalid(sr,sc+1)){ 
        s.push_back('R');bfs(s,sr,sc+1);vis[sr][sc+1]=0;
        if(!s.empty()) s.pop_back();
    }
    if(isvalid(sr-1,sc)){ 
        s.push_back('U');bfs(s,sr-1,sc);vis[sr-1][sc]=0;
        if(!s.empty()) s.pop_back();
    }
    if(isvalid(sr,sc-1)){
        s.push_back('L');bfs(s,sr,sc-1);vis[sr][sc-1]=0;
        if(!s.empty()) s.pop_back();
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    string s;
    bfs(s,0,0);
    for(auto &val:v){
        cout<<val<<endl;
    }
}

int main(){
    fastio();
    ll t;cin>>t;
    while(t--){
        solve();
    }
}