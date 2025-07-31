#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cntA = 0, cntB = 0, cntC = 0;
        int left = 0, right = 0;
        int ans = 0;
        while(right < n) {
            cntA += s[right] == 'a';
            cntB += s[right] == 'b';
            cntC += s[right] == 'c';
            while(cntA && cntB && cntC && left < right) {
                cntA -= s[left] == 'a';
                cntB -= s[left] == 'b';
                cntC -= s[left] == 'c';
                left++;
            }
            ans += left;
            right++;
        }
        return ans;
    }
};

int main() {
    Solution S;
    string s = "abc";
    cout << S.numberOfSubstrings(s) << endl;
    return 0;
}
// code_end
