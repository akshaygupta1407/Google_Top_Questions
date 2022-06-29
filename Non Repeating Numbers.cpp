/*
Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.
https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1/?page=1&difficulty[]=0&status[]=unsolved&company[]=Google&sortBy=submissions#
*/
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xr = 0;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            xr = xr ^ nums[i];
        }
        int mask = 1;
        while((mask&xr)==0)
        {
            mask = mask<<1;
        }
        int a = 0,b = 0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&mask)==0) a^=nums[i];
            else b^=nums[i];
        }
        res.push_back(a);
        res.push_back(b);
        if(a>b)
        swap(res[0],res[1]);
        return res;
    }
};
