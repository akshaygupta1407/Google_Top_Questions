/*
Given an integer numRows, return the first numRows of Pascal's triangle.

For example, given integer N= 4 then you have to print.
1  
1 1 
1 2 1 
1 3 3 1

Here for the third row, you will see that the second element is the summation of the above two-row elements i.e. 2=1+1, and similarly for row three 3 = 1+2 and 3 = 1+2.
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle(numRows);
        triangle[0].push_back(1);
        if(numRows<=1)
        {
            return triangle;
        }
        triangle[1].push_back(1);
        triangle[1].push_back(1);
        if(numRows<=2)
        {
            return triangle;
        }
        for(int i = 2;i<numRows;i++)
        {
            triangle[i].resize(i+1);
            triangle[i][0] = triangle[i][i] = 1;
            for(int j=1;j<i;j++)
            {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
        return triangle;
    }
};
