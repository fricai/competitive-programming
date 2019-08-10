#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const long long inf = 1e18;

struct edge {
	int a, b;
	long long cost;
};

signed main() {
	long long n, m, p; cin >> n >> m >> p;

	vector<edge> e(m);
	REP(i, 0, m) {
		long long a, b, c; cin >> a >> b >> c;
		e[i].a = a - 1;
		e[i].b = b - 1;
		e[i].cost = - c + p;
	}

	vector<long long> d(n, inf);
	d[0] = 0;
	bool x = 0;
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < m; ++j)
			if (d[e[j].a] < inf)
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {
					d[e[j].b] = max(-inf, d[e[j].a] + e[j].cost);
					if (i >= n && e[j].b == n - 1) x = 1;
				}
	}

	if (x || d[n - 1] == inf) cout <<  -1;
	else cout << max(0LL, -d[n - 1]);
}