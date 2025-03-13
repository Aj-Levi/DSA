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
#define fastio()\
ios_base::sync_with_stdio(false);\
cin.tie(nullptr)

// min number of reversals needed to make the string a valid exp.

int findMinimumCost(string str) {
    // odd condition
    if (str.length() % 2 == 1) return -1;

    stack<char> s;
    for (int i = 0; i < str.length(); i++) {

        char ch = str[i];

        if (ch == '{') s.push(ch);
        else{
            // ch is closed brace
            if (!s.empty() && s.top() == '{') s.pop();
            
            else s.push(ch);
        }
    }

    // stack contains invalid expression
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{') b++;
        else a++;

        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}