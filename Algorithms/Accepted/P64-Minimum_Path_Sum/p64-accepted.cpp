class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int column = grid.size();
        int row = grid[0].size();
        // cout << column << " " << row << endl;
        
        for (int i=1; i<column; ++i)
            grid[i][0] += grid[i-1][0];
        for (int i=1; i<row; ++i)
            grid[0][i] += grid[0][i-1];
        
        
        for (int i=1; i<column; ++i){
            for (int j=1; j<row; ++j){
                grid[i][j] = min(grid[i][j]+grid[i-1][j], grid[i][j]+grid[i][j-1]);
            }
        }
/*
        for (int i=0; i<column; ++i){
            for (int j=0; j<row; ++j)
                cout << grid[i][j] << " ";
            cout << endl;
        }
*/
        return grid[column-1][row-1];
    }
};