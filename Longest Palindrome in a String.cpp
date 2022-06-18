/*
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1/?page=2&company[]=Google&sortBy=submissions#

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).
*/
class Solution {
  public:
    string extendfrommiddle(string s,int i,int j)
    {
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalin (string S) {
        // code here
        string res = "";
        int n = S.length();
        for(int i=0;i<n;i++)
        {
            string s1 = extendfrommiddle(S,i,i);
            string s2 = extendfrommiddle(S,i,i+1);
            if(s1.length() > res.length())
            {
                res = s1;
            }
            if(s2.length() > res.length())
            {
                res = s2;
            }
        }
        return res;
    }
};
