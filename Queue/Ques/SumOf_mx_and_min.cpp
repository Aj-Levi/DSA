#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// find the max and the min element in all the subarrays of size k

// Just use sliding window maximum and sliding window minimum
// which we have done in arrays ques

class Solution {
public:
    vector<pair<int,int> > SlidingWindow(vector<int>& nums, int k) {
        deque<int> mx,mn;
        vector<pair<int,int> > ans;
        for(int i=0;i<k;i++){

            if(mx.empty()) mx.push_back(nums[i]);

            if(mn.empty()) mn.push_back(nums[i]);

            else{
                while(!mx.empty() && mx.back() < nums[i]) mx.pop_back();
                mx.push_back(nums[i]);

                while(!mn.empty() && mn.back() > nums[i]) mn.pop_back();
                mn.push_back(nums[i]);
            }
        }

        ans.push_back(make_pair(mx.front(),mn.front()));

        for(int i=k;i<nums.size();i++){

            if(nums[i-k]==mx.front()) mx.pop_front();

            if(nums[i-k]==mn.front()) mn.pop_front();

            while(!mx.empty() && mx.back() < nums[i]) mx.pop_back();
            mx.push_back(nums[i]);

            while(!mn.empty() && mn.back() > nums[i]) mn.pop_back();
            mn.push_back(nums[i]);

            ans.push_back(make_pair(mx.front(),mn.front()));
        }
        return ans;
    }
};