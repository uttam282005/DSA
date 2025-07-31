#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> isWord;
        int n = s.length();

        for(string word : wordDict) isWord[word] = true;

        vector<int> dp(n, 0);

        dp[n - 1] = isWord[s.substr(n - 1, 1)];


        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 2; j >= i; j--) {
                string prefix = s.substr(i, j - i + 1);
                if (isWord[prefix]) {
                    dp[i] |= dp[j + 1];
                }
            }

            if (isWord[s.substr(i, n)]) dp[i] = 1;
        }

        for(int i = 0; i < n; i++) cout << dp[i] << " ";

        cout << endl;

        return dp[0];
    }
};

int main() {
    Solution S;
    string s = "catsandog";
    vector<string> wordDict = {"cat", "dog", "cats", "sand", "dog"};
    cout << S.wordBreak(s, wordDict) << endl;
}
