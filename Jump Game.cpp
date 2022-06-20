/*
https://leetcode.com/problems/jump-game/
Jump Game 1 (Leetcode)
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return true;
        if(nums[0]==0)  return false;
        int maxreach = nums[0],steps = nums[0],jump = 1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)  return true;
            maxreach = max(maxreach,i+nums[i]);
            steps--;
            if(steps==0)
            {
                jump++;
                if(i>=maxreach) return false;
                steps = maxreach - i;
            }
        }
        return false;
    }
};

/*

Jump Game 2
https://leetcode.com/problems/jump-game-ii/
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return 0;
        if(nums[0]==0)  return -1;
        int maxreach = nums[0],steps = nums[0],jump = 1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)  return jump;
            maxreach = max(maxreach,i+nums[i]);
            steps--;
            if(steps==0)
            {
                jump++;
                if(i>=maxreach) return -1;
                steps = maxreach-i;
            }
        }
        return -1;
    }
};
