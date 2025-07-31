
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<long long, int>
#define ll long long
const ll INF = 1e18;

const int N = 1e5 + 5;
vector<pii> G[N]; // (neighbor, weight)
void solve() {
  int n, m;
  cin >> n >> m;

  // Input graph
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].pb({v, -1}); // all weights are -1
  }

  vector<ll> dist(n + 1, INF);
  vector<int> parent(n + 1, -1);

  dist[1] = -1;
  set<pii> st; // (dist, node)
  st.insert({dist[1], 1});

  while (!st.empty()) {
    auto [curDist, u] = *st.begin();
    st.erase(st.begin());

    for (auto [v, w] : G[u]) {
      if (dist[v] > curDist + w) {
        st.erase({dist[v], v}); // Remove old entry if present
        dist[v] = curDist + w;
        parent[v] = u;
        st.insert({dist[v], v});
      }
    }
  }

  if (dist[n] == INF) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  cout << -dist[n] << "\n"; // since weights are -1

  vi path;
  for (int u = n; u != -1; u = parent[u])
    path.pb(u);

  reverse(all(path));
  for (int u : path)
    cout << u << " ";
  cout << "\n";
}

int main() { solve(); }
