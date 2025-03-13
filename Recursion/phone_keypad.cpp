#include<iostream>
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
string s;
vector<string> v;
string m[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int it(char a){
    return a-'0';
}

void subset(string &temp,ll ind,ll i){
    if(ind==s.size()){
        v.push_back(temp);
        return;
    }
    ll num=it(s[ind]);
    string str=m[num];
    if(i==str.size()){
        return;
    }
    subset(temp,ind,i+1);
    temp.push_back(str[i]);
    subset(temp,ind+1,0);
    temp.pop_back();
}

void solve(){
    cin>>s;
    string temp;
    subset(temp,0,0);
    for(auto &val:v) cout<<val<<endl;
}

int main(){
    fastio();
    ll t;cin>>t;
    while(t--){
        solve();
    }
}