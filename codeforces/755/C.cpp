#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

vector<int> succ, sizo;

int find(int x) {
	int y = x;
	while (y != succ[y]) y = succ[y];
	succ[x] = y;
	return y;
}

int link(int x, int y) {
	x = find(x); y = find(y);
	if (sizo[y] > sizo[x]) swap(x, y); // sizo of x > sizo of y
	succ[y] = x;
	sizo[x] += sizo[y];
}

bool check(int x, int y) {
	return (find(x) == find(y));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	succ.resize(n); sizo.resize(n, 1);
	REP(i, 0, n) succ[i] = i;
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
