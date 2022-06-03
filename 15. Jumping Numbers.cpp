/*
https://practice.geeksforgeeks.org/problems/jumping-numbers3805/1/#
Given a positive number X. Find the largest Jumping Number smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.
*/
class Solution {
  public:
  long long ans = 0;
  void bfs(long long X,long long num)
  {
      queue<long long>q;
      q.push(num);
      while(!q.empty())
      {
          num = q.front();
          q.pop();
          if(num<=X)
          {
              ans = max(ans,num);
              int lastdigit = num%10;
              if(lastdigit==0)
              {
                  q.push(num*10 + (lastdigit+1));
              }
              else if(lastdigit==9)
              {
                  q.push(num*10 + (lastdigit-1));
              }
              else
              {
                  q.push(num*10 + (lastdigit-1));
                  q.push(num*10 + (lastdigit+1));
              }
          }
      }
  }
    long long jumpingNums(long long X) {
        // code here
        for(long long i=1;i<=9 && i<=X;i++)
        {
            bfs(X,i);
        }
        return ans;
    }
};

/*
Problem Statement
https://www.codingninjas.com/codestudio/problems/jumping-numbers_1069220?leftPanelTab=0
You are given a positive integer N, your task is to find all the Jumping Numbers smaller than or equal to N.
A number is defined as a Jumping Number if all adjacent digits in it have an absolute difference of 1.
*/
#include<bits/stdc++.h>
void bfs(int X,int num,vector<int>&res)
{
    queue<int>q;
    q.push(num);
    while(!q.empty())
    {
        num = q.front();
        q.pop();
        if(num<=X)
        {
            res.push_back(num);
            int lastdigit = num%10;
            if(lastdigit==0)
            {
                q.push(num*10 + (lastdigit+1));
            }
            else if(lastdigit==9)
            {
                q.push(num*10 + (lastdigit-1));
            }
            else
            {
                q.push(num*10 + (lastdigit-1));
                q.push(num*10 + (lastdigit+1));
            }
        }
    }
}
vector<int> jumpingNumbers(int n)
{
	// Write your code here
    vector<int>res;
    res.push_back(0);
    for(int i=1;i<=9 && i<=n;i++)
    {
        bfs(n,i,res);
    }
    sort(res.begin(),res.end());
    return res;
}
