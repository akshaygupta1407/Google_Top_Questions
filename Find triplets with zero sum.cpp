/*
https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1/?page=1&company[]=Google&sortBy=submissions#

Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr,arr+n);
        for(int i=0;i<n-3;i++)
        {
            int a = arr[i];
            int l = i+1, e = n-1;
            while(l<e)
            {
                if(arr[i]+arr[l]+arr[e] == 0)
                {
                    return true;
                }
                else if(arr[i]+arr[l]+arr[e] < 0)
                {
                    l++;
                }
                else
                {
                    e--;
                }
            }
        }
        return false;
    }
};
