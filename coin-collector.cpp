#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 200000 + 5;
using ll = long long;

vector<int> G[N];
vector<int> GT[N];
ll scc[N];
vector<ll> SCC[N];
int component[N];
bool vis[N];
ll coins[N];
ll dp[N];

int n, m;

void dfs(int var, stack<int> &st) {
    if (vis[var])
        return;
    vis[var] = true;

    for (int child : G[var])
        dfs(child, st);

    st.push(var);
}

void dfs2(int var, int sec, ll &sum) {
    component[var] = sec;
    sum += coins[var];

    for (int child : GT[var]) {
        if (component[child] == -1)
            dfs2(child, sec, sum);
    }
}

void computeDAG() {
    for (int i = 1; i <= n; i++) {
        for (int u : G[i]) {
            if (component[i] != component[u]) {
                SCC[component[i]].push_back(component[u]);
            }
        }
    }
}

ll dfs_dp(int u) {
    if (dp[u] != -1)
        return dp[u];
    ll best = scc[u];
    for (int v : SCC[u]) {
        best = max(best, scc[u] + dfs_dp(v));
    }
    return dp[u] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill(component, component + N, -1);

    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
        dp[i] = LLONG_MIN; // “uncomputed”
    }

    for (int i = 0; i < m; i++) {
        int s, d;
        cin >> s >> d;
        G[s].push_back(d);
        GT[d].push_back(s);
    }

    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        dfs(i, st);
    }

    int sec = 1;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (component[node] == -1) {
            long long sum = 0;
            dfs2(node, sec, sum);
            scc[sec] = sum;
            sec++;
        }
    }

    computeDAG();

    fill(dp, dp + sec, -1);
    ll ans = 0;
    for (int i = 1; i <= sec; i++) {
        ans = max(ans, dfs_dp(i));
    }
    cout << ans << endl;

    return 0;
}
