/*
https://leetcode.com/problems/queue-reconstruction-by-height/
You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).
*/
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])  return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>ans(n,vector<int>(2,-1));
        for(int i=0;i<n;i++)
        {
            int count = people[i][1];
            for(int j=0;j<n;j++)
            {
                if(ans[j][0]==-1 && count==0)
                {
                    ans[j][0] = people[i][0];
                    ans[j][1] = people[i][1];
                    break;
                }
                else if(ans[j][0]==-1 || ans[j][0]>=people[i][0])
                {
                    count--;
                }
            }
        }
        return ans;
    }
};
