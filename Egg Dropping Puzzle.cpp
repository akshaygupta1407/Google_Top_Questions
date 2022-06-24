/*
https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1/?page=1&status[]=unsolved&status[]=attempted&company[]=Google&sortBy=submissions#
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.
*/
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int egg(int n,int k,vector<vector<int>>&dp)
    {
        if(k<=1)    return k;
        if(n==1)    return k;
        if(dp[n][k]!=-1)    return dp[n][k];
        int mn = INT_MAX,x,res;
        for(x=1;x<=k;x++)
        {
            res = max(egg(n-1,x-1,dp),egg(n,k-x,dp));
            mn = min(mn,res);
        }
        return dp[n][k] =  mn + 1;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(500,vector<int>(500,-1));
        return egg(n,k,dp);
    }
};
