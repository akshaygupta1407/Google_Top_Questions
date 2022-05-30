/*
https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?leftPanelTab=0
*/
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    vector<int>r,c;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==0)
            {
                r.push_back(i);
                c.push_back(j);
            }
        }
    }
    int n = r.size();
    for(int i=0;i<n;i++)
    {
        int row = r[i];
        int col = c[i];
        while(row-1>=0)
        {
            matrix[row-1][col] = 0;
            row--;
        }
        row = r[i];
        col = c[i];
         while(row+1<matrix.size())
        {
            matrix[row+1][col] = 0;
             row++;
        } 
        row = r[i];
        col = c[i];
        while(col-1>=0)
        {
            matrix[row][col-1] = 0;
            col--;
        }
        row = r[i];
        col = c[i];
         while(col+1<matrix[0].size())
        {
            matrix[row][col+1] = 0;
             col++;
        }
    }
}
