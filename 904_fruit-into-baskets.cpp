#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;
        int left = 0;
        int maxFruits = 0;
        for(int right = 0; right < n; right++) {
            cnt[fruits[right]]++;
            while(cnt.size() > 2 && left < right) {
                cnt[fruits[left]]--;
                if (cnt[fruits[left]] == 0) cnt.erase(fruits[left]);
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};

int main() {
    Solution S;
    vector<int> fruits = {1,2,3,2,2};
    cout << S.totalFruit(fruits);
    return 0;
}
