#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(q.empty()) q.push_back(nums[i]);
            else{
                // jo bhi current element process ho rha h na 
                // usse pehle jo bhi usse chote elements q me 
                // insert hue h wo kisi kaam k nhi h

                // bcoz jab dq (sliding window) se current 
                // element nikal rha hoga usse pehle hi ye 
                // elements remove ho chuke honge.

                // and ye elements to curr se chote bhi h. 
                // therefore jab tak ye elements window me 
                // rhenge tab tak ye kbhi bhi possible ans bn hi 
                // nhi payenge
                while(!q.empty() && q.back() < nums[i]) q.pop_back();
                q.push_back(nums[i]);
            }
        }
        ans.push_back(q.front());
        for(int i=k;i<nums.size();i++){
            if(nums[i-k]==q.front()) q.pop_front();
            while(!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);
            ans.push_back(q.front());
        }
        return ans;
    }
};