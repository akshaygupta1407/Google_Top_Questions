/*
https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1/?page=2&company[]=Google&sortBy=submissions#
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in str1 should map to the same character in str2
*/
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n = str1.length(), m = str2.length();
        if(n!=m)    return false;
        unordered_map<char,char>mpp1,mpp2;
        for(int i=0;i<n;i++)
        {
            if(mpp1.find(str1[i])==mpp1.end())
            {
                mpp1[str1[i]] = str2[i];
            }
            else 
            {
                char ch = mpp1[str1[i]];
                if(ch!=str2[i]) return false;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mpp2.find(str2[i])==mpp2.end())
            {
                mpp2[str2[i]] = str1[i];
            }
            else 
            {
                char ch = mpp2[str2[i]];
                if(ch!=str1[i]) return false;
            }
        }
        return true;
    }
};
