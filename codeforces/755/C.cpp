#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

vector<int> succ, depth;

void makeset(int n) {
	succ.resize(n); REP(i, 0, n) succ[i] = i;
	depth.resize(n, 1);
}

int find(int x) {
	if (x != succ[x]) {
		succ[x] = find(succ[x]);
		return succ[x];
	}
	else return x;
}

void link(int x, int y) {
	x = find(x); y = find(y);

	if (depth[x] > depth[y]) swap(x, y);
	if (depth[x] == depth[y]) depth[y] = depth[x] + 1;
	succ[x] = y;
}

bool check(int x, int y) {
	return (find(x) == find(y));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	makeset(n);

	REP(i, 0, n) {
		int u; cin >> u; --u;
		link(i, u);
	}

	vector<bool> ans(n, 0);
	REP(i, 0, n) ans[find(i)] = 1;

	int cnt = 0;
	REP(i, 0, n) cnt += ans[i];
	cout << cnt << '\n';
}
