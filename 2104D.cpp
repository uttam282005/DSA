#include <bits/stdc++.h>
using namespace std;

// Defines
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
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

const int M = 6000001;
const int N = 400001;

vector<int> is_prime(M);
vector<ll> sum_of_primes(N);

void sieve() {
  for (int i = 0; i < M; ++i)
    is_prime[i] = 1;

  for(int i = 2; i < M; i++) {
    if (is_prime[i]) {
      for(int j = 2 * i; j < M; j += i) {
        is_prime[j] = 0;
      }
    }
  }
}

void compute_sum_of_primes() {
  int j = 1;
  for(int i = 2; i < M && j < N; i++) {
    if (is_prime[i]) {
      sum_of_primes[j] = sum_of_primes[j - 1] + i;
      j++;
    }
  }
}

// Main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    sieve();
    compute_sum_of_primes();
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
  int n; cin >> n; vi v(n);
  rep(i, 0, n) cin >> v[i];
  sort(all(v), greater<int>());
  ll arr = 0;
  int keep = 0;
  for (int i = 0; i < n; i++) {
    arr += v[i];
    if (sum_of_primes[i + 1] <= arr) {
      keep = i + 1;
    }
  }
  cout << n - keep << endl;
}

/*
Author: Your Name
Date: 2025-05-17
Problem: Problem Name/URL
*/
