#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int INF = 1e9;
class Solution {
  public:
    int minCost(vector<vector<int>> &grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
        vector<int> prefixMin(n * m);
        vector<pair<int, pair<pair<int, int>, int>>> prev;
        vector<int> prevAns(n * m);
        vector<vector<int>> ind(n, vector<int>(m));

        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0)
                    dp[i][j][0] =
                        min(dp[i][j][0], grid[i][j] + dp[i - 1][j][0]);
                if (j > 0)
                    dp[i][j][0] =
                        min(dp[i][j][0], grid[i][j] + dp[i][j - 1][0]);


                prev.push_back({grid[i][j], {{i, j}, dp[i][j][0]}});
            }
        }

        sort(prev.begin(), prev.end());

        for (int i = 0; i < prev.size(); i++) {
            auto [pos, ans] = prev[i].second;
            ind[pos.first][pos.second] = i;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                prevAns[ind[i][j]] = dp[i][j][0];
            }
        }

        // for(int i = 0; i < n * m; i++) cout << prevAns[i] << " ";

        int mini = INF;
        for (int i = 0; i < n * m; i++) {
            mini = min(prevAns[i], mini);
            prefixMin[i] = mini;
            cout << prevAns[i] << endl;
        }

        for (int mo = 1; mo <= k; mo++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i > 0)
                        dp[i][j][mo] =
                            min({dp[i][j][mo], grid[i][j] + dp[i - 1][j][mo],
                                 prefixMin[ind[i][j]]});
                    if (j > 0)
                        dp[i][j][mo] =
                            min({dp[i][j][mo], grid[i][j] + dp[i][j - 1][mo],
                                 prefixMin[ind[i][j]]});

                    prevAns[ind[i][j]] = dp[i][j][mo];
                }
            }

            int mini = INF;
            for (int i = 0; i < n * m; i++) {
                mini = min(prevAns[i], mini);
                prefixMin[i] = mini;
            }
        }

        return dp[n - 1][m - 1][k];
    }
};

int main() {
    Solution S;
    vector<vector<int>> grid = {{1,3,3},{2,5,4},{4,3,5}};
    int k = 2;
    cout << S.minCost(grid, k);
    return 0;
}

// code_start
// code_end
