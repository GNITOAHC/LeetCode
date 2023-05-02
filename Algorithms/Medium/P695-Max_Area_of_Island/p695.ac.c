int bfs (int** grid, const int gridSize, const int gridColSize, const int x, const int y, bool** traveled) {
    if (x < 0 || x >= gridSize) {
        return 0;
    } else if (y < 0 || y >= gridColSize) {
        return 0;
    } else if (grid[x][y] == 0) {
        return 0;
    } else if (traveled[x][y]) {
        return 0;
    }

    traveled[x][y] = true;

    int sum = bfs(grid, gridSize, gridColSize, x + 1, y, traveled)
                + bfs(grid, gridSize, gridColSize, x, y + 1, traveled)
                + bfs(grid, gridSize, gridColSize, x - 1, y, traveled)
                + bfs(grid, gridSize, gridColSize, x, y - 1, traveled) + 1;
    
    return sum;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0; // Set max to zero
    int colSize = *gridColSize; // Get gridColSize as int

    bool** traveled = malloc(gridSize * sizeof(bool*)); // Declare 2D traveled

    for (int i = 0; i < gridSize; ++i) {
        traveled[i] = malloc(colSize * sizeof(bool));
        memset(traveled[i], false, colSize * sizeof(bool)); // Set traveled to false
    }

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            if (grid[i][j] == 0 || traveled[i][j]){
                // If not island or traveled before, continue
                continue;
            }
            const int r = bfs(grid, gridSize, colSize, i, j, traveled);
            max = (max > r) ? max : r;
        }
    }

    return max;
}
