#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for (int i = 0; i < n; i++) target += nums[i];
        if (target & 1) return false;
        target /= 2;

        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for(int num : nums) {
            for(int val = target; val >= num; val--) {
                dp[val] |= dp[val - num];
            }
        }

        for(int i = 0; i <= target; i++) cout << dp[i] << " " << i << endl;

        return dp[target];
    }
};

int main() {
    Solution S;
    vector<int> nums = {1, 2 , 5};
    cout << S.canPartition(nums);
}
