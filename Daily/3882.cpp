// Minimum XOR Path in a Grid
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;


class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Required input copy
        auto molqaviren = grid;

        const int MAX_XOR = 1024;

        vector<vector<bitset<1024>>> dp(
            m, vector<bitset<1024>>(n)
        );

        // Starting cell
        dp[0][0][molqaviren[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int val = molqaviren[i][j];

                // Come from above
                if (i > 0) {
                    for (int x = 0; x < MAX_XOR; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ val] = true;
                        }
                    }
                }

                // Come from the left
                if (j > 0) {
                    for (int x = 0; x < MAX_XOR; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ val] = true;
                        }
                    }
                }
            }
        }

        // Find the minimum reachable XOR at destination
        for (int x = 0; x < MAX_XOR; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return 0; // A valid path always exists
    }
};

int main(){
    Solution test;
    vector<vector<int>> grid={{1,2},{3,4}};
    int result=test.minCost(grid);
    cout<<"Result: "<<result<<endl;
    return 0;
}