#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;

    int dfs(int l, int r, vector<int> &cuts) {
        if (l + 1 == r) return 0;

        if (dp[l][r]) return dp[l][r];

        int minCost = INT_MAX;
        for (int i = 1; i < (int)cuts.size() - 1; i++) {
            int c = cuts[i];
            if (c > l && c < r) {
                minCost = min(minCost, dfs(l, c, cuts) + dfs(c, r, cuts) + r - l);
            }
        }

        if (minCost == INT_MAX) minCost = 0;

        return dp[l][r] = minCost;
    }

    int minCost(int n, vector<int> &cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return dfs(0, n, cuts);
    }
};

int main() {
    Solution S;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << S.minCost(n, cuts) << endl;
    return 0;
}
