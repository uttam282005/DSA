
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef long long ll;

struct Project {
  int start, end, reward;
};

bool cmp(const Project &a, const Project &b) {
  return a.end < b.end; // sort by end day
}

void solve() {
  int n;
  cin >> n;
  vector<Project> projects(n);
  vector<int> end_days(n);

  for (int i = 0; i < n; i++) {
    cin >> projects[i].start >> projects[i].end >> projects[i].reward;
  }

  sort(all(projects), cmp);

  for (int i = 0; i < n; i++) {
    end_days[i] = projects[i].end;
  }

  vector<ll> dp(n); // max reward considering projects[0...i]
  dp[0] = projects[0].reward;

  for (int i = 1; i < n; i++) {
    // Find the last project that ends before this one starts
    int j = upper_bound(all(end_days), projects[i].start - 1) -
            end_days.begin() - 1;

    ll include = projects[i].reward;
    if (j >= 0)
      include += dp[j];

    dp[i] = max(dp[i - 1], include);
  }

  cout << dp[n - 1] << '\n';
}

int main() {
  solve();
  return 0;
}
