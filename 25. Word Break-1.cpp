/*
Word break-1
https://www.codingninjas.com/codestudio/problems/word-break-1_758963?leftPanelTab=0
Word Break II
https://leetcode.com/problems/word-break-ii/
*/
class Solution {
public:
    vector<string>res;
    void findHelper(int index,unordered_set<string>set,string curr,string s)
    {
        if(index==s.length())
        {
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        string str = "";
        for(int i=index;i<s.length();i++)
        {
            str.push_back(s[i]);
            if(set.count(str))
            {
                findHelper(i+1,set,curr + str + " " ,s);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>set;
        for(auto x : wordDict)
        {
            set.insert(x);
        }
        string curr = "";
        findHelper(0,set,curr,s);
        return res;   
    }
};
