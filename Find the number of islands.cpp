/*
https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/?page=1&company[]=Google&sortBy=submissions#
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
*/
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0')
            return;
        if(grid[i][j]=='1')
        {
            grid[i][j] = '0';
        }
        dfs(grid,i+1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i+1,j+1,n,m);
        dfs(grid,i-1,j+1,n,m);
        dfs(grid,i-1,j-1,n,m);
        dfs(grid,i+1,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,grid.size(),grid[0].size());
                    count++;
                }
            }
        }
        return count;
    }
};
