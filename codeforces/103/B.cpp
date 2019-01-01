#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

int cnt = 1;
vector<vector<int>> adj;
vector<int> vis;

void dfs(int s) {
    vis[s] = 1;
    for (auto &v : adj[s])
        if (!vis[v]) {
            dfs(v);
            ++cnt;
        }
}

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n); vis.resize(n, 0);
    REP(i, 0, m) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    bool ans = 0;
    if (n == m) {
        dfs(0);
        if (cnt == n) ans = 1;
    }
    cout << (ans ? "FHTAGN!" : "NO");
}