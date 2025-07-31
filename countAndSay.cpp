#include <bits/stdc++.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

class Solution {
public:
  void skipLeadingZeroes(int &p, string version) {
    while (p < version.size() and version[p] == '0')
      p++;
  }

  int compareVersion(string version1, string version2) {
    int p1 = 0;
    int p2 = 0;

    while (p1 < version1.size() || p2 < version2.size()) {
      skipLeadingZeroes(p1, version1);
      skipLeadingZeroes(p2, version2);
      string rev1 = "";

      while (p1 < version1.size() and version1[p1] != '.') {
        rev1 += version1[p1];
        p1++;
      }

      if (rev1 == "")
        rev1 = "0";

      string rev2 = "";

      while (p2 < version2.size() and version2[p2] != '.') {
        rev2 += version2[p2];
        p2++;
      }

      if (rev2 == "")
        rev2 = "0";

      if (p1 < version1.size() && version1[p1] == '.')
        p1++;
      if (p2 < version2.size() && version2[p2] == '.')
        p2++;

      if (stoi(rev1) < stoi(rev2)) {
        return -1;
      } else if (stoi(rev1) > stoi(rev2)) {
        return 1;
      }
    }

    return 0;
  }
};

int main() {
  Solution S;
  cout << S.compareVersion("1.2", "1.10") << endl;
  return 0;
}
