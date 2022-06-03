/*
https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557?leftPanelTab=0
https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1/
Similar to Allocation book problem
solved by using binary Search
*/
#include<bits/stdc++.h>
bool isPossible(vector<int> &boards,int n,int k,int mid)
{
    int painter = 1,currsum = 0;
    for(int i=0;i<n;i++)
    {
        if(boards[i]>mid)
            return false;
        else if(boards[i] + currsum > mid)
        {
            painter++;
            if(painter > k)
                return false;
            currsum = boards[i];
        }
        else
        {
            currsum+=boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here
    int s = 0,e = 0;
    int sum = 0,n = boards.size();
    for(int i=0;i<n;i++)
    {
        sum+=boards[i];
    }
    e = sum;
    int ans = -1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(isPossible(boards,n,k,mid))
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return ans;
}
