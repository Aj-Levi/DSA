#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+10;

// kisi bhi vertex ko root mante hue tree ki max depth cal kro 
// ab us max depth wale node ko root manke jo max depth aae whi
// dia of tree h :) 

vector<int> g[N];
int depth[N];

void dfs(int vertex,int par=0){
    for(auto &child:g[vertex]){
        if(child==par){
            continue;
        }
        depth[child]+=depth[vertex]+1;
        dfs(child,vertex);
    }
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int mx=-1;
    int mx_node;
    for(int i=1;i<=n;i++){
        if(mx < depth[i]){
            mx=depth[i];
            mx_node=i;
        }
    }
    depth[mx_node]=0;
    dfs(mx_node);
    mx=(*max_element(depth,depth+N)); // diameter
    cout<<mx<<endl;
}