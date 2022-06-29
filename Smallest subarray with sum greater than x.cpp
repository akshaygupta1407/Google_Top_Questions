/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.
https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1/?page=1&difficulty[]=0&status[]=unsolved&company[]=Google&sortBy=submissions#
*/
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int sum = 0;
        int i=0,j=0;
        int count = 0,mx = INT_MAX;
        while(i<n && j<n)
        {
            while(sum<=x && j<n)
            {
                sum+=arr[j];
                j++;
                count++;
                if(sum>x)
                {
                    mx = min(mx,count);
                }
            }
            while(sum>x && i<n)
            {
                sum-=arr[i];
                i++;
                count--;
                if(sum>x)
                {
                    mx = min(mx,count);
                }
            }
        }
        while(sum>x && i<n)
        {
            sum-=arr[i];
            i++;
            count--;
            if(sum>x)
            {
                mx = min(mx,count);
            }
        }
        return mx;
    }
};
