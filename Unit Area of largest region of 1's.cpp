/*

Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/?page=1&status[]=unsolved&company[]=Google&sortBy=submissions

*/
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid,i+1,j,n,m) + dfs(grid,i,j+1,n,m) + dfs(grid,i-1,j,n,m) + dfs(grid,i,j-1,n,m) 
        + dfs(grid,i+1,j+1,n,m) + dfs(grid,i-1,j+1,n,m) + dfs(grid,i-1,j-1,n,m) + dfs(grid,i+1,j-1,n,m);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count = max(count,dfs(grid,i,j,n,m));
                }
            }
        }
        return count;
    }
};
