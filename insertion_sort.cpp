#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        ll j=i-1,toSwap=v[i];
        while(toSwap<v[j] && j>=0) swap(v[j+1],v[j]),j--;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}