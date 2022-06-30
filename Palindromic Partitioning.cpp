/*
https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1/?page=1&status[]=unsolved&company[]=Google&sortBy=submissions#
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.
*/
class Solution{
public:
    int dp[501][501];
    bool isPal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    int Partition(string &s,int i,int j)
    {
        if(i>=j)    return 0;
        if(isPal(s,i,j))    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp = 1 + Partition(s,i,k) + Partition(s,k+1,j);
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return Partition(str,0,str.length()-1);
    }
};
