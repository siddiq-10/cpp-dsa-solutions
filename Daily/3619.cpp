
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip water and already visited cells
                if (grid[i][j] == 0)
                    continue;

                long long islandSum = grid[i][j];

                stack<pair<int, int>> st;
                st.push({i, j});

                // Mark as visited
                grid[i][j] = 0;

                while (!st.empty()) {
                    auto [r, c] = st.top();
                    st.pop();

                    // Explore four directions
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if (nr >= 0 && nr < m &&
                            nc >= 0 && nc < n &&
                            grid[nr][nc] > 0) {

                            islandSum += grid[nr][nc];

                            // Mark before pushing to avoid duplicates
                            grid[nr][nc] = 0;

                            st.push({nr, nc});
                        }
                    }
                }

                // Check whether this island's sum is divisible by k
                if (islandSum % k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
