// 3665 ~ 
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<array>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1'000'000'007;

        int m = grid.size();
        int n = grid[0].size();

        // dp[j][0] = paths arriving from the left
        // dp[j][1] = paths arriving from above
        vector<array<int, 2>> dp(n + 1, {0, 0});

        // Starting point: initially we can choose either direction
        dp[1] = {1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    // Mirror: swap the incoming direction states
                    dp[j + 1] = {
                        dp[j + 1][1],
                        dp[j][0]
                    };
                } else {
                    // Empty cell: combine both ways
                    int ways = (dp[j + 1][1] + dp[j][0]) % MOD;

                    dp[j + 1] = {ways, ways};
                }
            }
        }

        // Destination's valid paths
        return dp[n][0];
    }
};