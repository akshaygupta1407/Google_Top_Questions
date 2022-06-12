/*
https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1/?page=1&company[]=Google&sortBy=submissions#

Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place).
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....

If there are multiple solutions, find the lexicographically smallest one.
*/
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& nums){
        
        // Your code here
        if(n%2==0)
        {
            for(int i=0;i<n-1;i+=2)
            {
                swap(nums[i],nums[i+1]);
            }
        }else
        {
            for(int i=0;i<n-2;i+=2)
            {
                swap(nums[i],nums[i+1]);
            }
        }
        
    }
};
