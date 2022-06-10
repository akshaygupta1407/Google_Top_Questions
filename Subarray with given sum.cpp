/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

In case of multiple subarrays, return the subarray which comes first on moving from left to right.

https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/?page=1&company[]=Google&sortBy=submissions
*/
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int i=0,j=0;
        long long int sum = 0;
        while(i<n || j<n)
        {
            // sum+=arr[i];
            if(sum==s)
            {
                return {j+1,i};
            }
            else if(sum > s)
            {
                sum-=arr[j];
                j++;
            }
            else
            {
                sum+=arr[i];
                i++;
            }
        }
        return {-1};
    }
};
