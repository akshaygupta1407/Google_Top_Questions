/*
https://leetcode.com/problems/majority-element-ii/
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int count1 =0,count2 = 0;
        int element1=INT_MIN,element2 = INT_MIN;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==element1)   count1++;
            else if(nums[i]==element2)   count2++;
            else if(count1==0)
            {
                element1 = nums[i];
                count1++;
            }
            else if(count2==0)
            {
                element2 = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int>res;
        count1=0,count2=0;
        for(auto x : nums)
        {
            if(x==element1) count1++;
            if(x==element2) count2++;
        }
        if(count1 > size/3) res.push_back(element1);
        if(count2 > size/3) res.push_back(element2);
        return res;
    }
};
