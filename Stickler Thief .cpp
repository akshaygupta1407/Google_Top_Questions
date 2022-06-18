/*
https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?page=2&company[]=Google&sortBy=submissions#
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.
*/
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int cost(int arr[], int n,vector<int>&dp)
    {
        if(n<0) return 0;
        if(n==0 || n==1)    return dp[n] = arr[n];
        if(dp[n]!=-1)   return dp[n];
        return dp[n] = arr[n] + max(cost(arr,n-2,dp),cost(arr,n-3,dp));
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n+1,-1);
        return max(cost(arr,n-1,dp),cost(arr,n-2,dp));
    }
};
