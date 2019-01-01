#include <array>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<array<int, 2>> intervals;

void dfs(int s) {
    vis[s] = 1;
    for (auto &v : adj[s])
        if (!vis[v])
            dfs(v);
}

int main() {
    int n; cin >> n;
    adj.resize(n);
    intervals.reserve(n);
    while (n--) {
        int q, m = intervals.size(); cin >> q;
        if (q == 1) {
            int x, y; cin >> x >> y;
            REP(i, 0, m) {
                int a = intervals[i][0], b = intervals[i][1];
                if ((x < a && a < y) || (x < b && b < y))
                    adj[i].emplace_back(m);
                if ((a < x && x < b) || (a < y && y < b))
                    adj[m].emplace_back(i);
            }
            intervals.push_back({x, y});
        } else if (q == 2) {
            vis.clear(); vis.resize(m, 0);
            int a, b; cin >> a >> b;
            dfs(--a);
            cout << ((vis[--b]) ? "YES" : "NO") << "\n";
        }
    }
}