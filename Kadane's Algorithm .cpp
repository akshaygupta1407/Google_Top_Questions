/*
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1/?page=1&company[]=Google&sortBy=submissions#

*/


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int cummsum = 0,mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            cummsum+=arr[i];
            mx = max(mx,cummsum);
            if(cummsum<0)
            cummsum = 0;
        }
        return mx;
    }
};

