#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_R = 2024;
// dp[r][c] stores the sum of squares of the sub-pyramid rooted at row r, col c
ll memo[MAX_R][MAX_R];
bool vis[MAX_R][MAX_R];

// Helper to get the value at (row, col)
inline ll getValue(ll r, ll c) {
    return (r * (r - 1) / 2) + c;
}

// Optimized Memoized DFS
ll dfs(int r, int c) {
    if (r <= 0 || c <= 0 || c > r) return 0;

    if (vis[r][c]) return memo[r][c];

    ll val = getValue(r, c);
    
    // Inclusion-Exclusion:
    // Left parent + Right parent - Overlapping intersection parent
    memo[r][c] = val * val 
               + dfs(r - 1, c - 1) 
               + dfs(r - 1, c) 
               - dfs(r - 2, c - 1);

    vis[r][c] = true;
    return memo[r][c];
}

void solve() {
    ll n;
    cin >> n;

    // Determine row r and column c of n
    ll r = 1;
    while (r * (r + 1) / 2 < n) {
        r++;
    }
    ll start_r = (r - 1) * r / 2 + 1;
    ll c = n - start_r + 1;

    cout << dfs(r, c) << "\n";
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
