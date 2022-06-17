/*
https://practice.geeksforgeeks.org/problems/edit-distance3702/1/?page=2&company[]=Google&sortBy=submissions#
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
*/
class Solution {
  public:
  int helper(string s, string t,int n,int m,vector<vector<int>>&dp)
  {
      if(n==0)  return m;
      if(m==0)  return n;
      if(dp[n][m]!=-1)  return dp[n][m];
      if(s[n-1]==t[m-1])
        return dp[n][m] = helper(s,t,n-1,m-1,dp);
      else
      {
          int insert,del,replace;
          insert = helper(s,t,n,m-1,dp);
          del = helper(s,t,n-1,m,dp);
          replace = helper(s,t,n-1,m-1,dp);
          return dp[n][m] = min(insert,min(del,replace))+1;
      }
  }
    int editDistance(string s, string t) {
        // Code here
        int n = s.length(),m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(s,t,n,m,dp);
    }
};
