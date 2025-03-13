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
const int N=1e5+10;
int a[N];

ll merge(ll l,ll r,ll mid){
    ll l_sz=mid-l+1;
    ll r_sz=r-mid;
    int lft[l_sz+1],rt[r_sz+1];
    for(int x=0;x<l_sz;x++){
        lft[x]=a[x+l];
    }
    for(int x=0;x<r_sz;x++){
        rt[x]=a[x+mid+1];
    }
    lft[l_sz]=rt[r_sz]=INT_MAX;
    ll i=0,j=0,ptr=l,res=0;
    while(ptr<=r){
        if(lft[i]<=rt[j]) a[ptr]=lft[i],i++,ptr++;
        else a[ptr]=rt[j],j++,ptr++,res+=(l_sz-i);
    }
    return res;
}

ll mergesort(ll l,ll r){
    ll res=0;
    if(l<r){
        ll mid=(l+r)/2;
        res+=mergesort(l,mid);
        res+=mergesort(mid+1,r);
        res+=merge(l,r,mid);
    }
    return res;
}

void solve(){
    ll n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<mergesort(0,n-1)<<endl;;
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

int main(){
    fastio();
    ll t;cin>>t;
    while(t--){
        solve();
    }
}