/*
https://practice.geeksforgeeks.org/problems/anagram-1587115620/1/?page=2&company[]=Google&sortBy=submissions

Given two stringsaandbconsisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other.
*/
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        if(a==b)    return true;
        if(a.length()!=b.length())  return false;
        unordered_map<char,int>m;
        for(int i=0;i<a.length();i++)
        {
            m[a[i]]++;
            m[b[i]]--;
        }
        for(auto x : m)
        {
            if(x.second!=0)
            return false;
        }
        return true;
        
    }

};
