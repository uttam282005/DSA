#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <utility>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

// defines
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
#define pi 3.141592653589793238462
#define set_bits __builtin_popcountll

// typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128 ell;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds;

// constants
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll llinf = 1e18;
const int n = 2e5 + 1;

// factorials and modular arithmetic
int fact[n + 1];
int inv_fact[n + 1];

#define debug(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void _f(const char *name, T &&value) {
  cout << name << " : " << value << endl;
}
template <typename T, typename... Ts>
void _f(const char *names, T &&value, Ts &&...rest) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ":" << value << "|";
  _f(comma + 1, rest...);
}

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class A, class B> void _print(pair <A, B> p);
template <class A> void _print(vector <A> v);
template <class A> void _print(set <A> v);
template <class A, class B> void _print(map <A, B> mp);
template <class A> void _print(multiset <A> v);
template <class A, class B> void _print(pair <A, B> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class A> void _print(vector <A> v) {cerr << "[ "; for (A i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class A> void _print(set <A> v) {cerr << "[ "; for (A i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class A> void _print(multiset <A> v) {cerr << "[ "; for (A i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class A, class B> void _print(map <A, B> mp) {cerr << "[ "; for (auto i : mp) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}
ll getrandomnumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    map<pair<int, int>, int> cnt;
    int free = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0) {
                free++;
            }
           continue; 
        }
        
        if (b[i] == 0) {
            cnt[{0, 0}]++;
            continue;
        }
        
        int ai = abs(a[i]);
        int bi = abs(b[i]);
        int g = gcd(ai, bi);
        ai = ai / g;
        bi = bi / g;
        
        if ((a[i] < 0 and b[i] < 0) or (a[i] > 0 and b[i] > 0)) {
            cnt[{-bi, ai}]++;
        } else cnt[{bi, ai}]++;
    }
    
    int ans = 0;
    for(auto [key, val] : cnt) {
        ans = max(ans, val);
    }
    ans += free;
    
    cout << ans << endl;
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