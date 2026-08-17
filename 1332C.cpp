#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		int ans = 0; // minimal replacements required for this test case
		for (int i = 0; i < (k + 1) / 2; i++) { // group positions i and k-1-i within each period
				vector<int> freq(26, 0); // frequency of letters for the current group across all blocks
				for (int j = 0; j < n / k; j++) { // iterate over each block of length k
						int idx1 = j * k + i; // position i in the j-th block
						int idx2 = (j + 1) * k - i - 1; // mirrored position within the same block
						freq[s[idx1] - 'a']++; // count character at idx1
						if (idx1 != idx2) // when k is odd and i is the center, avoid double counting
								freq[s[idx2] - 'a']++; // count character at idx2
				}
				int mx = *max_element(freq.begin(), freq.end()); // majority letter count in this group
				int s = accumulate(freq.begin(), freq.end(), 0LL); // total characters considered in this group
				ans += s - mx; // changes needed = total - majority
		}
		cout << ans << '\n'; // output result for the test case
}

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}

		return 0;
}

/*
Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/

