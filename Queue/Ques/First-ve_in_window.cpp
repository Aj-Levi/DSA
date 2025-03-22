#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i=0;i<k;i++) if(arr[i]<0) q.push_back(arr[i]);
        if(!q.empty()) ans.push_back(q.front());
        else ans.push_back(0);
        for(int i=k;i<arr.size();i++){
            if(!q.empty() && q.front()==arr[i-k]) q.pop_front();
            if(arr[i]<0) q.push_back(arr[i]);

            if(!q.empty()) ans.push_back(q.front());
            else ans.push_back(0);
        }
        return ans;     
    }
};