
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> tree[N];
int subordinates[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 2; i <= n; ++i) {
    int boss;
    cin >> boss;
    tree[boss].push_back(i);
  }

  vector<bool> visited(n + 1, false);
  stack<pair<int, bool>> st; // {node, isBacktracking}
  st.push({1, false});

  while (!st.empty()) {
    auto [node, backtracking] = st.top();
    st.pop();
    if (backtracking) {
      int count = 0;
      for (int child : tree[node]) {
        count += subordinates[child] + 1;
      }
      subordinates[node] = count;
    } else {
      st.push({node, true});

      for (int subord : tree[node]) {
        st.push({subord, false});
        visited[subord] = true;
      }
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << subordinates[i] << " ";
  cout << "\n";

  return 0;
}
