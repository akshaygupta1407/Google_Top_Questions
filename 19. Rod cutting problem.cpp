/*
Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

 

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.

https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#
https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=3
*/
class Solution{
  public:
 
  int helper(int price[], int index,int size,vector<vector<int>>&dp)
  {
     if(index==0)
     {
         return size*price[0];
     }
     if(dp[index][size]!=-1)
     {
         return dp[index][size];
     }
     int notcut = helper(price,index-1,size,dp);
     int cut = INT_MIN;
     int rod_length = index + 1;
     if(rod_length<=size)
     {
         cut = price[index] + helper(price,index,size-rod_length,dp);
     }
     return dp[index][size] = max(cut,notcut);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(price,n-1,n,dp);
    }
};
