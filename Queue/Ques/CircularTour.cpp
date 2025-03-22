#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // If total gas is less than total cost, it's impossible to complete the circuit
        // else it is guaranteed that we can complete circuit
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;
        int balance=0,ans=0,n=gas.size();
        // here we are trying to find a poss ans by visiting 
        // each element exactly once
        for(int i=0;i<n;i++){
            balance+=(gas[i]-cost[i]);
            // If balance becomes negative, reset and start from the next station
            if(balance<0){
                ans=i+1;
                balance=0;
            }
        }
        return ans;
    }
};