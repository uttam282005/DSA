// Wrong solution
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1000;

class Solution {
public:
    int dp[N][N];
        int dfs(int l, int r, vector<int> &nums, int n) {
            if (l > r) return 0;

            if (dp[l][r]) return  dp[l][r];

            int maxCoins = INT_MIN;

            for(int i = l; i <= r; i++) {
                maxCoins = max(maxCoins, nums[l - 1] * nums[i] * nums[r + 1] + dfs(l, i - 1, nums, n) + dfs(i + 1, r, nums, n));
            }

            return dp[l][r] = maxCoins;
        }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2));

        for(int l =  n; l >= 1; l--) {
            for(int r = 1; r <= n; r++) {
                for(int i = l; i <= r; i++) {
                   dp[l][r] = max(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + nums[i] * nums[l - 1] * nums[r + 1]);
                }
            }
        }

        return dp[1][n];
    }
};

int main() {
    Solution S;
    vector<int> nums = {3, 1, 5, 8};
    cout << S.maxCoins(nums);
    return 0;
}
