#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <vector>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

// Defines
#define db double
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define itr(container) for (auto &it : container)
#define endl "\n"
#define ss second
#define gcd(a, b) __gcd(a, b)
#define vs vector<string>
#define um unordered_map
#define pb push_back
#define umii unordered_map<int, int>
#define sortv(arr) sort(arr.begin(), arr.end())
#define ff first
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

// Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128 ell;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const int N = 2e5 + 1;

// Factorials and Modular Arithmetic
int fact[N + 1];
int inv_fact[N + 1];


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

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
/*--------------------------------------------------------------------------------------------------------------------------*/



/**
 * Precompute factorials and inverse factorials modulo MOD.
 * Uses Fermat’s little theorem for modular inverse (MOD must be prime).
 */
void calculate_factorial_bulk() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[N - 1] = mminvprime(fact[N - 1], MOD);  // fact[n]^{-1} mod MOD
    for (int i = N - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

/**
 * Computes nCr % MOD using precomputed factorials.
 */
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

/**
 * Simple factorial function for small values of n (without mod).
 */
ll factorialSmall(int n) {
    if (n == 0 || n == 1) return 1;
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

/**
 * Computes nCr without mod (only for small inputs), avoids overflow up to ~20.
 */
ll c(int n, int r) {
    if (r < 0 || r > n) return 0;
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int inDeg[N], outDeg[N];
vector<int> G[N];
stack<int> path;

void dfs(int node) {
    while(G[node].size()) {
        int nextNode = G[node].back();
        G[node].pop_back();
        dfs(nextNode);
    }
    path.push(node);
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int s, d;
        cin >> s >> d;
        G[s].pb(d);
        inDeg[d]++;
        outDeg[s]++;
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (outDeg[i] - inDeg[i] != 1) { cout << "IMPOSSIBLE\n"; return; }
        } else if (i == n) {
            if (inDeg[i] - outDeg[i] != 1) { cout << "IMPOSSIBLE\n"; return; }
        } else {
            if (inDeg[i] != outDeg[i]) { cout << "IMPOSSIBLE\n"; return; }
        }
    }

    dfs(1);

    if(path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    while(!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
