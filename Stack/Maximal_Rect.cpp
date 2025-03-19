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

class Solution {
public:
    vector<int> NSE(vector<int> &v){
        int n=v.size();
        vector<int> nse(n,n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(!stk.empty()){
                while(!stk.empty() && v[stk.top()]>v[i]){
                    nse[stk.top()]=i;
                    stk.pop();
                }
            }
            stk.push(i);
        }
        return nse;
    }

    vector<int> PSE(vector<int> &v){
        int n=v.size();
        vector<int> pse(n,-1);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            if(!stk.empty()){
                while(!stk.empty() && v[stk.top()]>v[i]){
                    pse[stk.top()]=i;
                    stk.pop();
                }
            }
            stk.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int> &heights) {
        int n=heights.size();
        vector<int> nse=NSE(heights);
        vector<int> pse=PSE(heights);

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(nse[i]-pse[i]-1));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char> >& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int> >v;
        for(int i=0;i<m;i++) {
            vector<int> temp(n);
            for(int j=0;j<n;j++) temp[j]=matrix[i][j]-'0';
            v.push_back(temp);
        }

        int ans=largestRectangleArea(v[0]);

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]) v[i][j]+=v[i-1][j];
                ans=max(ans,largestRectangleArea(v[i]));
            }
        }

        return ans;
    }
};