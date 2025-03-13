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

void insert_At_Bottom(stack<int> &stk,int val){
    if(stk.empty()){
        stk.push(val);
        return;
    }

    int num = stk.top();
    stk.pop();

    insert_At_Bottom(stk,val);

    stk.push(num);
}

void rev(stack<int> &stk){
    if(stk.empty()) return;

    ll top = stk.top();
    stk.pop();

    rev(stk);
    insert_At_Bottom(stk,top);
}

int main() {
    fastio();
    return 0;
}