#include<iostream>
#include<set>
using namespace std;
#define ll long long 
set<string> ans;

void perm(string &s,ll ind){
    if(ind==s.size()){
        ans.insert(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[ind],s[i]);
        perm(s,ind+1);
        swap(s[ind],s[i]);
    }
}

int main(){
    string s;cin>>s;
    perm(s,0);
    for(auto &val:ans){
        cout<<val<<endl;
    }
}