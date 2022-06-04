/*
https://leetcode.com/problems/merge-intervals/
https://www.codingninjas.com/codestudio/problems/merge-intervals_699917?leftPanelTab=0
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        for(auto interval : intervals)
        {
            if(res.empty() || res.back()[1] < interval[0])
            {
                res.push_back(interval);
            }
            else
            {
                res.back()[1] = max(res.back()[1],interval[1]);
            }
        }
        return res;
    }
};
