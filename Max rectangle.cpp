/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.
https://practice.geeksforgeeks.org/problems/max-rectangle/1/?page=1&status[]=unsolved&status[]=attempted&company[]=Google&sortBy=submissions
*/

class Solution{
  public:
  int histo(vector<int>&heights,int n)
  {
      stack<int>st;
      int mxArea = 0;
      for(int i=0;i<=n;i++)
      {
          int currHeight = i==n ? 0 : heights[i];
          while(!st.empty() && currHeight < heights[st.top()])
          {
              int tp = st.top();
              st.pop();
              int width = st.empty() ? i : i-st.top()-1;
              int area = heights[tp]*width;
              mxArea = max(mxArea,area);
          }
          st.push(i);
      }
      return mxArea;
  }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res = 0;
        vector<int>v(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==1)
                v[j]+=M[i][j];
                else
                v[j] = 0;
            }
            res = max(res,histo(v,m));
        }
        return res;
    }
};
