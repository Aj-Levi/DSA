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

// Explaination : 

// consider a relation on the set of given n people
// where aRb <=> a knows b

// we have to find a person such that everyone knows him but he
// knows no one. i.e, xRp for all x 
// and pRx only for x=p

// therefore we have to find the maximal element of the set wrt 
// relation R.

// and as we know that if the maximal element of a set exists 
// then it is unique

// hence there can be at most one celeb. That's why we have used 
// the condition stk.size() > 1

// Also if both the persons don't know each other then both of 
// them cant be poss celebs bcoz a celeb is a person whom 
// everyone knows 

// And if both the persons know each other then also both of 
// them cant be poss celebs bcoz a celeb is a person who 
// doesn't know anyone.

class Solution {
public:
    int celebrity(vector<vector<int> >& mat) {
        stack<int> stk;
        int n=mat.size();
        for(int i=0;i<n;i++) stk.push(i);
        while(stk.size() > 1){
            int p1 = stk.top();stk.pop();
            int p2 = stk.top();stk.pop();

            if(mat[p1][p2] && !mat[p2][p1]) stk.push(p2);
            if(mat[p2][p1] && !mat[p1][p2]) stk.push(p1);
        }
        if(stk.empty()) return -1;
        int poss_celeb = stk.top(),temp=0;
        for(int i=0;i<n;i++){
            if(i==poss_celeb) continue;
            if(mat[i][poss_celeb]) temp++;
            if(mat[poss_celeb][i]) return -1;
        }

        return (temp==(n-1)?poss_celeb:-1);
    }
};