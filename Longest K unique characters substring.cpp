/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.
https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/?page=1&status[]=unsolved&company[]=Google&sortBy=submissions#
*/
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int>m;
        int i=0,j=0,mx=INT_MIN;
        while(j<s.length())
        {
            if(m.size()<=k)
            {
                if(m.size()==k && m.find(s[j])==m.end())
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                else
                {
                    m[s[j]]++;
                    mx = max(mx,j-i+1);
                    j++;
                }
            }
            else
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                {
                    m.erase(s[i]);
                }
                i++;
                
            }
        }
        if(m.size()<k)  return -1;
        return mx==INT_MIN ? -1 : mx;
    }
};
