/*
https://practice.geeksforgeeks.org/problems/interleaved-strings/1/?page=2&company[]=Google&sortBy=submissions#

Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

An interleaving of two strings S and T is a configuration such that it creates a new string Y from the concatenation substrings of A and B and |Y| = |A + B| = |C|

For example:

A = "XYZ"

B = "ABC"

so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you can create a string Y which can be equal to C.

Specifically, you just need to create substrings of string A and create substrings B and concatenate them and check whether it is equal to C or not.

Note: a + b is the concatenation of strings a and b.

Return true if C is formed by an interleaving of A and B, else return false.
*/


class Solution{
  public:
    /*You are required to complete this method */
    bool check(string A,int i, string B,int j, string C,int k,vector<vector<int>>&dp)
    {
        if(i==A.length())
        {
            return B.substr(j)==C.substr(k);
        }
        if(j==B.length())
        {
            return A.substr(i)==C.substr(k);
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        // bool ans = false;
        // if(C[k]==A[i] && check(A,i+1,B,j,C,k+1,dp) || )
        return dp[i][j] = ((C[k]==A[i] && check(A,i+1,B,j,C,k+1,dp)) ||  (C[k]==B[j] && check(A,i,B,j+1,C,k+1,dp)));
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        if(A.length() + B.length() != C.length())   return false;
        vector<vector<int>>dp(A.length()+1,vector<int>(B.length()+1,-1));
        return check(A,0,B,0,C,0,dp);
    }

};
