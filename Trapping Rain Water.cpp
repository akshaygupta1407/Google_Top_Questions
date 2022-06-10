/*
https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1/?page=1&company[]=Google&sortBy=submissions#

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 
*/
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int>left(n,0),right(n,0);
        left[0] = arr[0], right[n-1] = arr[n-1];
        for(int i=1;i<n;i++)
        {
            left[i] = max(left[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(right[i+1],arr[i]);
        }
        long long water = 0;
        for(int i=0;i<n;i++)
        {
            water += min(left[i],right[i]) - arr[i];
        }
        return water;
    }
};
