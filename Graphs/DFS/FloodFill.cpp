#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<pair<ll,ll> > mov;

bool isValid(ll i,ll j,ll m,ll n){
    return (i>=0 && j>=0 && i<m && j<n);
}

// TC -> O(m*n + 2*4) = O(V + 2*E)
void floodFill(ll sr,ll sc,ll oldcol,ll newcol,vector<vector<ll> >&v){
    v[sr][sc]=newcol;
    for(auto &movement: mov){
        ll destx=sr+movement.first,desty=sc+movement.second;
        if(!isValid(destx,desty,v.size(),v[0].size()) || v[destx][desty]!=oldcol) continue;
        floodFill(destx,desty,oldcol,newcol,v);
    }
}

int main(){
    mov.push_back(make_pair(1,0));
    mov.push_back(make_pair(-1,0));
    mov.push_back(make_pair(0,1));
    mov.push_back(make_pair(0,-1));
    return 0;
}