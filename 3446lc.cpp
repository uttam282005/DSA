#include <bits/stdc++.h>
#include <functional>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> ans(n, vector<int>(n));
    stack<pair<int, int>> st;
    vector<int> ele;

    // bottom triangle
    int j = 0;
    for(int i = 0; i < n; i++) {
      int nextX = i;
      int nextY = j;
      while(i < n && j < n) {
        nextX++;
        nextY++;
        ele.push_back(grid[nextX][nextY]);
        st.push({nextX, nextY});
      }

      sort(ele.begin()
           , ele.end(), greater<int>());

      while(!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        ans[x][y] = ele.back();
        ele.pop_back();
      }
    }
     // top triangle
    int i = 0;
    for(int j = 1; j < n; j++) {
      int nextX = i;
      int nextY = j;

      while(nextX < n and nextY < n) {
        nextX++;
        nextY++;
        ele.push_back(grid[nextX][nextY]);
        st.push({nextX, nextY});
      }

      sort(ele.begin(), ele.end());

      while (!st.empty()) {
        auto[x, y] = st.top();
        st.pop();
        ans[x][y] = ele.back();
        ele.pop_back();
      }
    }
    return ans;
  }
};

int main() {
  Solution S;
  return 0;
}
