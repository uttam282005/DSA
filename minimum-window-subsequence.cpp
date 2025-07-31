#include <bits/stdc++.h>
using namespace std;

string minimumWindowSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    int minLen = INT_MAX, minStart = -1;

    for (int i = 0; i < n; ++i) {
        if (s[i] != t[0]) continue;

        int j = 0, k = i;
        // Forward scan to match the entire t
        while (k < n && j < m) {
            if (s[k] == t[j]) j++;
            k++;
        }

        // If matched the entire t
        if (j == m) {
            int end = k - 1;
            // Backward scan to minimize window
            j = m - 1;
            k = end;
            while (j >= 0) {
                if (s[k] == t[j]) j--;
                k--;
            }
            k++; // Adjust after last decrement

            if (end - k + 1 < minLen) {
                minLen = end - k + 1;
                minStart = k;
            }
            i = k; // skip unnecessary work
        }
    }

    return (minStart == -1) ? "" : s.substr(minStart, minLen);
}

int main() {
    string s = "abcdebdde", t = "bde";
    cout << minimumWindowSubsequence(s, t) << endl;
    return 0;
}
