/*
https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_839724
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0,e = n-1;
        int index1 = -1, index2 = -1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] < target)
            {
                s = mid+1;
            }
            else if(nums[mid]>target)
            {
                e = mid-1;
            }
            else if(nums[mid]==target)
            {
                index1 = mid;
                if((mid-1 >= 0) && nums[mid-1]!=target)
                    break;
                e = mid-1;
            }
        }
        s = 0,e = n-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] < target)
            {
                s = mid+1;
            }
            else if(nums[mid]>target)
            {
                e = mid-1;
            }
            else if(nums[mid]==target)
            {
                index2 = mid;
                if((mid+1 < n) && nums[mid+1]!=target)
                    break;
                s = mid+1;
            }
        }
        return {index1,index2};
    }
};
