#include <bits/stdc++.h>
#include <clocale>
#include <string>
#include <vector>
using namespace std;

// Defines
#define db double
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define itr(container) for (auto &it : container)
#define ss second
#define gcd(a, b) __gcd(a, b)
#define vs vector<string>
#define um unordered_map
#define pb push_back
#define umii unordered_map<int, int>
#define sortv(arr) sort(arr.begin(), arr.end())

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
const int N = 2e5 + 1;

// Factorials and Modular Arithmetic
int fact[N + 1];
int inv_fact[N + 1];

// Binary Exponentiation
ll binPow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll res = binPow(a, b / 2);
  res = (res * res) % MOD;
  if (b % 2 == 1)
    res = (res * (a % MOD)) % MOD;
  return res;
}

// Precomputing factorials and inverse factorials
void calculate_factorial_bulk() {
  fact[0] = 1;
  for (int i = 1; i <= N; i++)
    fact[i] = 1ll * fact[i - 1] * i % MOD;
  inv_fact[N] = binPow(fact[N], MOD - 2) % MOD;
  for (int i = N - 1; i >= 0; i--)
    inv_fact[i] = 1ll * inv_fact[i + 1] * (i + 1) % MOD;
}

// Calculate factorial for small numbers
ll factorialSmall(int n) {
  if (n == 0 || n == 1)
    return 1;
  ll res = 1;
  for (int i = 2; i <= n; i++)
    res *= i;
  return res;
}

// nCr calculation with modular arithmetic
ll nCr(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  return 1ll * fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

// Combination without modular arithmetic
ll c(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  ll res = 1;
  for (int i = 1; i <= r; i++) {
    res *= n - i + 1;
    res /= i;
  }
  return res;
}

// Derangement Calculation
ll derangements(int n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 0;
  ll D = 0, sign = 1;
  for (int k = 0; k <= n; k++) {
    ll term = (sign * inv_fact[k]) % MOD;
    term = (term + MOD) % MOD;
    term = (term * fact[n]) % MOD;
    D = (D + term) % MOD;
    sign *= -1;
  }
  return D;
}

#define debug(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void _f(const char *name, Arg1 &&arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void _f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ":" << arg1 << "|";
  _f(comma + 1, args...);
}

ll gcd(ll a, ll b) {
  if (b > a)
    return gcd(b, a);
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll expo(ll a, ll b, ll mod) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

void extendgcd(ll a, ll b, ll *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  ll x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
}

ll mminv(ll a, ll b) {
  ll arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {
  ll val1 = fact[n];
  ll val2 = ifact[n - r];
  ll val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}

void google(int t) { cout << "Case #" << t << ": "; }

vector<ll> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<ll> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i)
        arr[j] = 1;
    }
  return vect;
}

ll solve(ll n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll l, r; cin >> l >> r;
  if (l == 0) cout << solve(r);
  else
  cout << solve(r) - solve(l - 1) << endl;

  return 0;
}


ll solve(ll r) {
  string R = to_string(r);
  int N = R.length();

  ll dp[20][11][2][2] = {}; // pos, prev_digit, leading_zero, tight

  dp[0][10][1][1] = 1; // At pos 0, no digit used (10 = dummy), leading zero, tight = 1

  for (int pos = 0; pos < N; pos++) {
    for (int prev = 0; prev <= 10; prev++) { // prev digit from 0-9 or 10 = none
      for (int lead = 0; lead <= 1; lead++) {
        for (int tight = 0; tight <= 1; tight++) {
          int ub = tight ? R[pos] - '0' : 9;
          for (int d = 0; d <= ub; d++) {
            if (d == prev && !lead) continue; // disallow same digit twice (except leading zeros)

            int n_lead = lead & (d == 0);
            int n_tight = tight & (d == ub);

            int new_prev = (n_lead ? 10 : d); // keep prev as 10 if still leading zeros

            dp[pos + 1][new_prev][n_lead][n_tight] += dp[pos][prev][lead][tight];
          }
        }
      }
    }
  }

  ll ans = 0;
  for (int prev = 0; prev <= 9; prev++) {
    ans += dp[N][prev][0][0]; // non-leading-zero, non-tight
    ans += dp[N][prev][0][1]; // non-leading-zero, tight
  }

  return ans;
}
