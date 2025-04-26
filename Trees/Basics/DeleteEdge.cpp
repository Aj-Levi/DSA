#include<iostream>
#include<vector>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
const int N=1e5+10;
const int m=1e9+7;

vector<int> g[N];
int weight[N];
long long subtree_sum[N];

void dfs(int vertex,int par=-1){
    subtree_sum[vertex]+=weight[vertex];
    for(auto &child:g[vertex]){
        if(child==par){
            continue;
        }
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);
    long long ans=0;
    for(int i=2;i<=n;i++){
        long long part1=subtree_sum[i];
        long long part2=subtree_sum[1]-part1;
        ans=max(ans,(part1*1ll*part2)%m);
    }
    cout<<ans<<endl;
}