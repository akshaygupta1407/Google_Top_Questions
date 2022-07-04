/*
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1/?page=1&status[]=unsolved&company[]=Google&sortBy=submissions#
Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.
*/
class Solution{
public:
    int helper(int idx, int W, int val[], int wt[],vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            return (W/wt[0])*val[0];
        }
        if(dp[idx][W]!=-1)  return dp[idx][W];
        int skip = helper(idx-1,W,val,wt,dp);
        int take = 0;
        if(wt[idx]<=W)
        {
            take = val[idx] + helper(idx,W-wt[idx],val,wt,dp);
        }
        return dp[idx][W] = max(skip,take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return helper(N-1,W,val,wt,dp);
    }
};
