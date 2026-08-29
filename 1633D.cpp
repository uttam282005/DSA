#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n), c(n);

    for (int &x : b)
        cin >> x;

    for (int &x : c)
        cin >> x;

    vector<int> cost(1001, INF);
    cost[1] = 0;

    for (int cur = 1; cur <= 1000; cur++) {
        for (int x = 1; x <= cur; x++) {
            if (cost[cur] == INF) continue;

            int nxt = cur + cur / x;

            if (nxt <= 1000) {
                cost[nxt] = min(cost[cur] + 1, cost[nxt]);
            }
        }
    }

    vector<int> ops(n);

    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        ops[i] = cost[b[i]];
        totalCost += ops[i];
    }

    k = min(k, totalCost);

    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= ops[i]; j--) {
            dp[j] = max(
                dp[j],
                dp[j - ops[i]] + c[i]
            );
        }
    }

    cout << dp[k] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
