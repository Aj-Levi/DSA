#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;

ll Partition(ll l,ll r){
    ll ct=0;
    for(int i=l+1;i<=r;i++){
        if(v[i]<=v[l]) ct++;
    }
    swap(v[l],v[l+ct]);
    ll p=l+ct;
    ll i=l,j=r;
    while(i<p && j>p){
        if(v[i]<=v[p]) i++;
        if(v[j]>v[p]) j--;
        if(v[i]>v[p] && v[j]<v[p]) swap(v[i],v[j]),i++,j--;
    }
    return p;
}

void quicksort(ll l,ll r){
    if(l>=r) return;
    ll p=Partition(l,r);
    quicksort(l,p-1);
    quicksort(p+1,r);
}

int main(){
    ll n;cin>>n;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        v.push_back(x);
    }
    quicksort(0,n-1);
    for(auto &val:v){
        cout<<val<<' ';
    }
    cout<<endl;
}