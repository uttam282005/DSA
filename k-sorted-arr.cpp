#include <bits/stdc++.h>
using namespace std;
// User function template for C++

class Solution {
public:
  class cmp {
  public:
    int *arr;
    cmp(int *arr) { this->arr = arr; }

    bool operator()(int i, int j) { return arr[i] > arr[j]; }
  };
  string isKSortedArray(int arr[], int n, int k) {
    cmp cm(arr);
    priority_queue<int, vector<int>, cmp> pq(cm);

    for (int i = 0; i < k; i++) {
      pq.push(i);
    }

    for (int i = 0; i < n - k; i++) {
      pq.push(i + k);
      if (abs(pq.top() - i) <= k) {
        cout << i << " " << pq.top() << endl;
        pq.pop();
      } else
        return "No";
    }

    for (int i = n - k; i < n; i++) {
      if (abs(pq.top() - i) <= k) {
        cout << i << " " << pq.top() << endl;
        pq.pop();
      } else
        return "No";
    }

    return "Yes";
  }
};
int main() {
  Solution S;
  // Example usage:
  // auto res = S.yourFunctionName(arguments);
  // cout << res << endl;
  int n = 19;
  int k = 12;
  int arr[] = {10, 27, 13, 28, 31, 29, 15, 7,  30, 19,
               47, 49, 25, 2,  20, 43, 44, 35, 12};
  cout << S.isKSortedArray(arr, n, k);
  return 0;
}
