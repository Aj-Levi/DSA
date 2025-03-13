#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define fastio() \
ios_base::sync_with_stdio(false); \
cin.tie(nullptr)

void py(){
    cout<<"YES"<<endl;
}
void pn(){
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
        int x;cin>>x;temp.push_back(x);
    }
    return temp;
}
vector<ll> v;
ll n,m;

bool canAllocate(ll mid){
    ll ct=1,pages=0;
    for(int i=0;i<n;i++){
        if(pages+v[i]<=mid) pages+=v[i];
        else{
            if(v[i]>mid) return false;
            else pages=v[i],ct++;
        }
    }
    return ct<=m;
}

void solve(){
    v.clear();
    cin>>n>>m;
    v=vin(n);
    //sort(all(v));
    ll sum=accumulate(all(v),0);

    ll lo=0,hi=sum,mid;
    while(hi-lo>1){
        mid=(lo+hi)/2;
        if(canAllocate(mid)) hi=mid;
        else lo=mid+1;
    }
    if(canAllocate(lo)) cout<<lo<<endl;
    else if(canAllocate(hi)) cout<<hi<<endl;
    else cout<<"not possible"<<endl;
}

int main(){
    fastio();
    ll t;cin>>t;
    while(t--){
        solve();
    }
}