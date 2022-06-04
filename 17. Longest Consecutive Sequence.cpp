/*
https://leetcode.com/problems/longest-consecutive-sequence/
https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_759408?leftPanelTab=0

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return n;
        sort(nums.begin(),nums.end());
        int count=1,mx = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1] == 1)
            {
                count++;
            }
            else if(nums[i]==nums[i-1])
                continue;
            else
            {
                mx = max(mx,count);
                count = 1;
            }
        }
        mx = max(mx,count);
        return mx;
    }
};
