#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> a1, a2;
vector<bool> explored;
 
void dfs(int v, bool b) {
    explored[v] = true;
    if (b) {
        a1.push_back(v);
    } else {
        a2.push_back(v);
    }
    for (auto i : adj[v]) {
        if (!explored[i]) {
            dfs(i, !b);
        }
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    adj.clear();
    adj.resize(n, {});
    a1.clear();
    a2.clear();
    a1.reserve(n);
    a2.reserve(n);
    
    explored.resize(n);
    fill(explored.begin(), explored.end(), false);
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, true);
    if (a1.size() <= n / 2) {
        cout << a1.size() << "\n";
        for (auto i : a1) {
            cout << i + 1 << " ";
        }
    } else {
        cout << a2.size() << "\n";
        for (auto i : a2) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}