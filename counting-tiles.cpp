#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, m;
vector<int> transitions[1 << 10];

void generate_transitions(int pos, int curr_mask, int next_mask) {
    if (pos == n) {
        transitions[curr_mask].push_back(next_mask);
        return;
    }
    if ((curr_mask & (1 << pos)) != 0) {
        // Already filled, move on
        generate_transitions(pos + 1, curr_mask, next_mask);
    } else {
        // Place vertical tile
        generate_transitions(pos + 1, curr_mask, next_mask | (1 << pos));

        // Place horizontal tile (2 rows)
        if (pos + 1 < n && !(curr_mask & (1 << (pos + 1)))) {
            generate_transitions(pos + 2, curr_mask, next_mask);
        }
    }
}

int main() {
    cin >> n >> m;
    int total_masks = 1 << n;

    for (int mask = 0; mask < total_masks; ++mask) {
        generate_transitions(0, mask, 0);
    }

    vector<vector<int>> dp(m + 1, vector<int>(total_masks));
    dp[0][0] = 1;

    for (int col = 0; col < m; ++col) {
        for (int mask = 0; mask < total_masks; ++mask) {
            for (int next_mask : transitions[mask]) {
                dp[col + 1][next_mask] = (dp[col + 1][next_mask] + dp[col][mask]) % MOD;
            }
        }
    }

    cout << dp[m][0] << endl;
    return 0;
}
