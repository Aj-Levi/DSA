#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <iomanip>
#include <ios>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <numeric>
#include <unordered_map>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define fastio() \
ios_base::sync_with_stdio(false); \
cin.tie(nullptr)
const int M = 1e9 + 7;

inline void py() {
    cout << "YES" << endl;
}
inline void pn() {
    cout << "NO" << endl;
}

ll binmul(ll a, ll b) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % M;
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

ll bin_exp(ll a, ll b) {
    ll ans = 1;
    a %= M;
    while (b) {
        if (b & 1) ans = binmul(ans, a);
        a = binmul(a, a);
        b >>= 1;
    }
    return ans;
}

void pv(vll &v) {
    for (auto &val : v) {
        cout << val << ' ';
    }
    cout << endl;
}

vll vin(ll n) {
    vll temp;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        temp.pb(x);
    }
    return temp;
}

class Solution {
public:
    string FirstNonRepeating(string &s) {
        queue<char> q;
        int hsh[26]={0};
        string ans;

        for(auto &ch: s){
            hsh[ch-'a']++;
            if(hsh[ch-'a']==1) q.push(ch);
            while(!q.empty() && hsh[q.front()-'a']>1) q.pop();
            if(!q.empty()) ans.push_back(q.front());
            else ans.push_back('#');
        }

        return ans;
    }
};

void solve() {
    return;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}