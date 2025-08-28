#include <bits/stdc++.h>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        stack<tuple<int, int, bool>> recurse;
        recurse.push({0, target, false});

        vector<int> cur;
        while(!recurse.empty()) {
            auto [ ind, target, isBacktracking ] = recurse.top();
            if (isBacktracking) candidates.pop_back();

            if (target == 0) ans.push_back(cur);
            if (ind < 0 or ind > n) continue;

            for(int i = ind; i < n; i++) {
                if (i > ind and candidates[i] == candidates[i - 1]) continue;

                if (candidates[i] > target) continue;

                cur.push_back(candidates[i]);
                recurse.push({i + 1, target - candidates[i], false});
                recurse.push({i + 1, target, true});
            }
        }

        return ans;
    }
};

int main() {
    Solution S;
    return 0;
}
