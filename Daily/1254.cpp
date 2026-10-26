// Number of Closed Islands
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        // Out of bounds or already water
        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid[r][c] == 1) {
            return;
        }

        // Mark this land cell as visited
        grid[r][c] = 1;

        // Explore all four directions
        dfs(grid, r - 1, c); // Up
        dfs(grid, r + 1, c); // Down
        dfs(grid, r, c - 1); // Left
        dfs(grid, r, c + 1); // Right
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Step 1: Remove land connected to the boundary
        for (int r = 0; r < m; r++) {
            dfs(grid, r, 0);
            dfs(grid, r, n - 1);
        }

        for (int c = 0; c < n; c++) {
            dfs(grid, 0, c);
            dfs(grid, m - 1, c);
        }

        // Step 2: Count remaining islands
        int count = 0;

        for (int r = 1; r < m - 1; r++) {
            for (int c = 1; c < n - 1; c++) {
                if (grid[r][c] == 0) {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }
};
