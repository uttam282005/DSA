#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            dp[i][0] += dp[i - 1][0] + grid[i][0];
        }

        for(int j = 1; j < m; j++) {
            dp[0][j] += dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

 int i = n - 1, j = m - 1;
    vector<int> path;

    while (i > 0 || j > 0) {
        path.push_back(grid[i][j]);

        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Push the starting cell
    path.push_back(grid[0][0]);

        for(int i = 0; i < (int)path.size(); i++) {
            cout << path[i] << " ";
        }

        return dp[n - 1][m - 1];
    }
};

int main() {
   Solution S;
   vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

   S.minPathSum(grid);
}
