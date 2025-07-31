
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const ll INF = 1e18;

int main() {
  int n, m;
  cin >> n >> m;

  unordered_map<int, vector<P>> adj(n + 1); // adj[u] = { {v, cost}, ... }
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  vector<ll> dist(n + 1, INF);
  dist[1] = 0;

  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, 1}); // {distance, node}

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u])
      continue;

    for (auto [v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
}
