class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        auto changeIsland = [&](int A, int B) -> void {
            queue<pair<int, int>> q;
            q.push(make_pair(A, B));
            int dir_x[4] = {1, 0, -1, 0}, dir_y[4] = {0, 1, 0, -1};
            while (!q.empty()) {
                const int a = q.front().first;
                const int b = q.front().second;
                q.pop();
                for (int i=0; i<4; ++i) {
                    if (a+dir_x[i] < 0 || a+dir_x[i] >= grid.size()) continue;
                    if (b+dir_y[i] < 0 || b+dir_y[i] >= grid[0].size()) continue;
                    if (grid[a+dir_x[i]][b+dir_y[i]] == '1') {
                        grid[a+dir_x[i]][b+dir_y[i]] = '0';
                        q.push(make_pair(a+dir_x[i], b+dir_y[i]));
                    }
                }
            }
        };
        
        int count = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    changeIsland(i, j);
                    ++count;
                }
            }
        }
        
        return count;
    }
};