/*
https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1/?page=2&company[]=Google&sortBy=submissions#

Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
*/
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>res;
        deque<int>dq;
        int i = 0;
        for(i=0;i<k;i++)
        {
            while(!dq.empty() && arr[i]>=arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(i;i<n;i++)
        {
            res.push_back(arr[dq.front()]);
            while(!dq.empty() && dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && arr[i]>=arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(arr[dq.front()]);
        return res;
    }
};
