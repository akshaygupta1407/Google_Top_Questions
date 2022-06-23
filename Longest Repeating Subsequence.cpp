/*
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1/?page=1&difficulty[]=0&status[]=unsolved&status[]=attempted&status[]=bookmarked&company[]=Google&sortBy=submissions#
Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.
*/
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=n;j++)
		        {
		            if(str[i-1]==str[j-1] && i!=j)
		            {
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }
		            else
		            {
		                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}

};
