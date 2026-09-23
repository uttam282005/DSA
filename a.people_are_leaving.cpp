#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;

public:
    DSU(int n) {
        parent.resize(n + 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void remove(int x) {
        parent[x] = find(x + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // n + 1 is the sentinel
    DSU dsu(n + 1);

    while (m--) {
        char type;
        int x;

        cin >> type >> x;

        if (type == '-') {
            dsu.remove(x);
        } else {
            int ans = dsu.find(x);

            if (ans == n + 1)
                cout << -1 << '\n';
            else
                cout << ans << '\n';
        }
    }

    return 0;
}
