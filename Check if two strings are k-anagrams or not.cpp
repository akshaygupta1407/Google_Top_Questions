/*
https://practice.geeksforgeeks.org/problems/check-if-two-strings-are-k-anagrams-or-not/1/?page=1&status[]=unsolved&company[]=Google&sortBy=submissions#

Given two strings of lowercase alphabets and a value K, your task is to complete the given function which tells if  two strings are K-anagrams of each other or not.

Two strings are called K-anagrams if both of the below conditions are true.
1. Both have same number of characters.
2. Two strings can become anagram by changing at most K characters in a string.
*/
class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        if(str1.length()!=str2.length())    return false;
        vector<int>res(26,0);
        for(int i=0;i<str1.length();i++)
        {
            res[str1[i]-'a']++;
            res[str2[i]-'a']--;
        }
        int count = 0;
        for(auto x : res)
        {
            if(x>0) count+=x;
        }
        return count<=k;
    }
};
