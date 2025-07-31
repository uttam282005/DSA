#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();

        vector<int> dp(n, 0);

        // dp[i][j] = Max sum that can be obtained by partioning a subarray
        // starting at index i and ending at j
        for (int i = n - 1; i >= 0; i--) {
            int maxi = INT_MIN;
            for (int j = i; j <= k + i - 1 && j < n; j++) {
                maxi = max(maxi, arr[j]);
                if (j + 1 >= n) {
                    dp[i] = max(dp[i], maxi * (j - i + 1));
                } else {
                    dp[i] = max(dp[i], dp[j + 1] + maxi * (j - i + 1));
                }
            }
        }

        return dp[0];
    }
};

int main() {
    Solution S;
    vector<int> arr = {1,4,1,5,7,3,6,1,9,9,3};
    int k = 4;
    cout << S.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}
