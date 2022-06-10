/*
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/?page=1&company[]=Google&sortBy=submissions#
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
       stack<int>s;
       for(int i=0;i<n;i++)
       {
           s.push(i);
       }
       while(s.size()>1)
       {
           int A = s.top();
           s.pop();
           int B = s.top();
           s.pop();
           if(M[A][B])
           {
               s.push(B);
           }
           else
           {
               s.push(A);
           }
       }
       int c = s.top();
       s.pop();
       for(int i=0;i<n;i++)
       {
           if(i!=c && (M[c][i] || !M[i][c]))
           return -1;
       }
       return c;
    }
};
