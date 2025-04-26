#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+10;

vector<int> graph[N];
int subtree_sum[N];
int even_ct[N];

void dfs(int vertex,int parent=-1){ // O(V+E)
    /*take action on vertex after entering 
    the vertex.*/
    if(vertex%2==0){
        even_ct[vertex]++;
    }
    subtree_sum[vertex]+=vertex;
    for(auto &child:graph[vertex]){
        /*take action on child before
        entering the child node*/
        if(child==parent){
            continue;
        }
        dfs(child,vertex);
        /*take action on child after exiting
        child node*/
        subtree_sum[vertex]+=subtree_sum[child];
        even_ct[vertex]+=even_ct[child];
    }
    /*take action on vertex before exiting
    the vertex*/
}