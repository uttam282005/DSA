#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
  public:
    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n, INT_MAX);
        vector<vector<bool>> isPalindrome(n, vector<bool>(n));

        isPalindrome[0][0] = true;

        for (int i = 0; i < n; i++)
            isPalindrome[i][i] = true;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (i + 1 == j)
                        isPalindrome[i][j] = true;
                    else if (isPalindrome[i + 1][j - 1])
                        isPalindrome[i][j] = true;
                }
            }
        }

        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (isPalindrome[i][j] and dp[j + 1] != INT_MAX) {
                    int nextCuts = j + 1 >= n ? 0 : 1 + dp[j + 1];
                    dp[i] = min(dp[i], nextCuts);
                }
            }
        }

        return dp[0];
    }
};

int main() {
    Solution S;
    string s = "aab";
    cout << S.minCut(s);
    return 0;
}
