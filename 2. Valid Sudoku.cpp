//code
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, column[9][9] = {0}, subgroup[9][9] = {0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num = board[i][j] - '0' - 1, k = i/3 * 3 + j/3;
                    if(row[i][num]==1 || column[j][num]==1 || subgroup[k][num]==1)
                        return false;
                    row[i][num]= column[j][num]= subgroup[k][num]=1;
                }
            }
        }
        return true;
    }
};
