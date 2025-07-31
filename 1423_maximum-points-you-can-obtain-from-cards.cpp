#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for(int i = 0; i < k; i++) total += cardPoints[i];

        int maxScore = total;
        for(int i = 0; i < k; i++) {
            total += cardPoints[n - i - 1];
            total -= cardPoints[k - i - 1];
           maxScore = max(maxScore, total);
        }

        return maxScore;
    }
};

int main() {
    Solution S;
    vector<int> cardPoints = {9,7,7,9,7,7,9};
    int k = 7;
    cout << S.maxScore(cardPoints, k) << endl;
    return 0;
}
