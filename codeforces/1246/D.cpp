#include <iostream>
#include <queue>
#include <set>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int N = 1 << 17;
int n, p[N], d[N];
set<int> g[N];
queue<int> q;

void dfs(int u = 0) {
	for (int v : g[u]) {
		d[v] = d[u] + 1;
		dfs(v);
	}
}

void solve(int u) {
	int &x = p[u];
	if (x == -1) return;
	if (g[x].size() == 1) solve(x);
	else {
		g[x].erase(u);
		x = *g[x].begin();
		g[x].insert(u);
		solve(u);
		q.push(u);
	}
}

void print(int u = 0) {
	cout << u << ' ';
	for (int v : g[u]) print(v);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	p[0] = -1;
	rep(u, 1, n) {
		cin >> p[u];
		g[p[u]].insert(u);
	}
	dfs();

	int u = 0;
	rep(v, 0, n) if (d[v] > d[u]) u = v;
	solve(u);
	print();
	cout << '\n' << q.size() << '\n';
	while(!q.empty()) cout << q.front() << ' ', q.pop();
}