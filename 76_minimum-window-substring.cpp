#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool compare(unordered_map<char, int> &charInT,
                 unordered_map<char, int> &charInS) {
        int ScontainsT = 1;
        for (auto [c, frqInT] : charInT) {
            ScontainsT &= (frqInT <= charInS[c]);
        }
        return ScontainsT;
    }

    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> charInT;
        unordered_map<char, int> charInS;
        int minLen = m + 1;
        int minL = m;
        int minR = m;

        for (char c : t)
            charInT[c]++;

        int left = 0;
        for (int right = 0; right < m; right++) {
            charInS[s[right]]++;
            while (compare(charInT, charInS)) {
                int curLen = right - left + 1;
                if (curLen < minLen) {
                    minL = left;
                    minR = right;
                    minLen = curLen;
                }
                charInS[s[left]]--;
                left++;
            }
        }
        return s.substr(minL, minR - minL + 1);
    }
};

int main() {
    Solution S;
    string s = "a", t = "a";
    cout << S.minWindow(s, t);
    return 0;
}
