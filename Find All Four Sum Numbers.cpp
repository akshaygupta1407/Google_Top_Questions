/*
https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1/?page=2&company[]=Google&sortBy=submissions#
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.
*/
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j = i+1; j<n; j++)
            {
                int l = j+1, e = n-1;
                while(l<e)
                {
                    int sum = arr[i] + arr[j] + arr[l] + arr[e];
                    if(sum == k)
                    {
                        vector<int>quad(4,0);
                        quad[0] = arr[i];
                        quad[1] = arr[j];
                        quad[2] = arr[l];
                        quad[3] = arr[e];
                        res.push_back(quad);
                        while(l < e && arr[l]==quad[2])
                            l++;
                        while(l < e && arr[e]==quad[3])
                            e--;
                    }
                    else if(sum < k)    l++;
                    else e--;
                }
                while(j+1<n && arr[j]==arr[j+1])
                    j++;
                
            }
            while(i+1<n && arr[i]==arr[i+1])
                    i++;
        }
        return res;
    }
};
