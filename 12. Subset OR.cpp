/*
https://www.codingninjas.com/codestudio/problems/subset-or_2105455?leftPanelTab=0
You are given an array/list ‘ARR’ of ‘N’ positive integers’. Your task is to find out the size of the smallest subset with the maximum OR possible. That means that among all subsets that have OR of its elements maximum, you need to report the size of the smallest such subset.
Using dp
*/
#include<bits/stdc++.h>
int helper(vector<int> &a,int curr,int n,int xr,vector<vector<int>>&dp)
{
    if(n<=0)
    {
        if(curr==xr)
        {
            return 0;
        }
        else
        {
            return 1000000000;
        }
    }
    if(dp[n][curr]!=-1)
    {
        return dp[n][curr];
    }
    //skipped
    int x = helper(a,curr,n-1,xr,dp);
    //taken
    int y = 1 + helper(a,(curr|a[n-1]),n-1,xr,dp);
    return dp[n][curr] = min(x,y);
}
int subsetOR(vector<int> &a) {
    //    Write your code here
    int xr = 0;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        xr = xr | a[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(xr+1,-1));
    return helper(a,0,n,xr,dp);
}
