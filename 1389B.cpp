
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				int n, k, Z;
				cin >> n >> k >> Z;

				vector<int> a(n);
				for (auto &x : a) cin >> x;

				ll ans = 0;

				for (int z = 0; z <= Z && 2 * z <= k; ++z) {
						int r = k - 2 * z;  // Net number of right moves after allocating z left moves (each left needs a compensating right)

						ll base = accumulate(a.begin(), a.begin() + r + 1, 0LL);  // 0LL ensures 64-bit accumulation
						int bestPair = 0;
						for (int i = 1; i <= min(r + 1, n - 1); ++i) {
								bestPair = max(bestPair, a[i] + a[i - 1]);
						}

						// Each left-right cycle contributes exactly the sum of the chosen adjacent pair.
						ll res = base + 1LL * z * bestPair;
						ans = max(ans, res);
				}

				cout << ans << '\n';
		}

		return 0;
}

// Time Complexity (per test case): O(n * min(Z, k/2))
// Space Complexity (per test case): O(n)

