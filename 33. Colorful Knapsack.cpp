/*
0-1 knapsack for basics
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).
*/
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int ks(int W, int wt[], int val[], int n,vector<vector<int>>&dp)
    {
        if(n==0 || W==0)
        return dp[n][W] = 0;
        
        if(dp[n][W]!=-1)
        {
            return dp[n][W];
        }
        
        if(W < wt[n-1])
        {
            return dp[n][W] = ks(W,wt,val,n-1,dp);
        }
        else
        {
            return dp[n][W] = max((val[n-1] + ks(W-wt[n-1],wt,val,n-1,dp)),ks(W,wt,val,n-1,dp));
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return ks(W,wt,val,n,dp);
    }
};


/*
coloful knapsack
https://www.codingninjas.com/codestudio/problems/colorful-knapsack_630415?leftPanelTab=0
You are given 'N' stones labeled from 1 to 'N'. The 'i-th' stone has the weight W[i]. There are 'M' colors labeled by integers from 1 to 'M'. The 'i-th' stone has the color C[i] which is an integer between 1 to 'M', both inclusive.
You have been required to fill a Knapsack with these stones. The Knapsack can hold a total weight of 'X'.
You are required to select exactly 'M' stones; one of each color. The sum of the weights of the stones must not exceed 'X'. Since you paid a premium for a Knapsack with capacity 'X', you are required to fill the Knapsack as much as possible.
Write a program to calculate the best way to fill the Knapsack - that is, the unused capacity should be minimized.
*/
#include<bits/stdc++.h>
int solve(vector<vector<int>> &v, int i, int m, int x, vector<vector<int>> &dp){
    if(i==m){
        return 0;
    }
    if(dp[i][x]!=-2){
        return dp[i][x];
    }
    int ans=-1;
    for(int k: v[i]){
        if((x-k)>=0){
            int a = solve(v, i+1, m, x-k, dp);
            if(a!=-1){
                ans = max(ans, k+a);
            }
        }
    }
    return dp[i][x]=ans;
}
int colorfulKnapsack(int w[], int c[], int n, int m, int x){
    vector<vector<int>> v(m);
    for(int i=0; i<n; i++){
        v[c[i]-1].push_back(w[i]);
    }
    vector<vector<int>> dp(m, vector<int>(x+1, -2));
    sort(v.begin(), v.end());
    int a = solve(v, 0, m, x, dp);
    if(a==-1){
        return a;
    }
    return x-a;
}
