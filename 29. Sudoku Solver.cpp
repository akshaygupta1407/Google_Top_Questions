/*
https://leetcode.com/problems/sudoku-solver/
https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919?leftPanelTab=0
*/
class Solution {
public:
    bool check(vector<vector<char>>& board,int i,int j,char ch)
    {
        int row = i - i%3, col = j - j%3;
        for(int x=0;x<9;x++)
        {
            if(board[x][j]==ch) return false;
        }
        for(int y=0;y<9;y++)
        {
            if(board[i][y]==ch) return false;
        }
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                if(board[row+x][col+y]==ch) return false;
            }
        }
        return true;
    }
    bool solver(vector<vector<char>>& board,int i,int j)
    {
        if(i==9)    return true;
        if(j==9)    return solver(board,i+1,0);
        if(board[i][j]!='.')    return solver(board,i,j+1);
        
        for(char ch = '1';ch<='9';ch++)
        {
            if(check(board,i,j,ch))
            {
                board[i][j] = ch;
                if(solver(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0,0);
    }
};
