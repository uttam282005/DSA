#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// Defines
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cout << #x << " = " << x << endl

// Typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

// Function prototypes
void solve();

// Main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vll v(n);
  string s;
  cin >> s;
  bool all_ones = true;
  rep(i, 0, n) cin >> v[i], all_ones &= (s[i] == '1');
  int pos = -1;
  rep(i, 0, n) {
    if (s[i] == '0')
      v[i] = -1e13, pos = i;
  }
  ll max_sum = 0;
  ll cur_sum = 0;
  for (int i = 0; i < n; i++) {
    cur_sum += v[i];
    max_sum = max(cur_sum, max_sum);
    if (cur_sum < 0)
      cur_sum = 0;
  }
  if (max_sum > k || (all_ones and max_sum != k)) {
    cout << "NO\n";
    return;
  }
  if (all_ones and max_sum == k) {
    cout << "YES\n";
    for (auto it : v)
      cout << it << " ";
    cout << endl;
    return;
  }
  ll b = 0;
  ll cu = 0;
  for (int i = pos + 1; i < n; i++) {
    cu += v[i];
    b = max(cu, b);
  }
  cu = 0;
  long long a = 0;
  for (int i = pos - 1; i >= 0; i--) {
    cu += v[i];
    a = max(a, cu);
  }
  v[pos] = k - a - b;
  cout << "YES\n";
  for (auto it : v)
    cout << it << " ";
  cout << endl;
}

/*
Author: Your Name
Date: 2025-05-18
Problem: Problem Name/URL
*/
