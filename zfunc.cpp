#include <bits/stdc++.h>
using namespace std;

void zf(string s, int n) {
  vector<int> z(n);

  int l = 0;
  int r = 0;

  for(int i = 1; i < n; i++) {
    if (i <= r) {
      z[i] = min(z[i - l], r - i + 1);
    }

    while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }

    if (i + z[i] - 1 > r) {
      l = i; r = i + z[i] - 1;
    }
  }
}

int main() {
    return 0;
}
