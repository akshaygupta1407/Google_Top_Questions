/*
https://leetcode.com/problems/maximum-subarray/
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int mx = INT_MIN;
        for(auto x : nums)
        {
            currsum+=x;
            mx = max(mx,currsum);
            if(currsum<0)
                currsum = 0;
            
        }
        return mx;
    }
};
