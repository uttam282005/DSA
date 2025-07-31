#include <bits/stdc++.h>
using namespace std;

void findBridges(int node, int parent = -1) {
    vis[node] = true;
    tin[node] = mintin[node] = timer++;

    for (int child : graph[node]) {
        if (child == parent)
            continue;

        if (!vis[child]) {
            findBridges(child, node);
            if (mintin[child] > tin[node]) {
                bridges.push_back({child, node});
            }
        }
        mintin[node] = min(mintin[node], mintin[child]);
    }
}
int main() { return 0; }
