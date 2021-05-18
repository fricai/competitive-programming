#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int X = 700;
int g[X][X];

void solve() {
	int m, k; cin >> m >> k;
	vector<int> a(k);
	for (auto &x : a) cin >> x, m -= x;
	assert(m == 0);

	auto ok = [&](int n) -> bool {
		priority_queue<pair<int, int>> q;

		auto add = [&](int f, int v) {
			if (f > 0) q.push({f, v});
		};
		
		auto valid = [&](int i, int j) {
			return 0 <= i && i < n && 0 <= j && j < n;
		};
		
		auto fine = [&](int i, int j, int x) {
			for (auto dx : {-1, +1})
				for (auto dy : {-1, +1})
					if (valid(i + dx, j + dy) && g[i + dx][j + dy] == x)
						return 0;
			return 1;
		};

		rep(i, 0, n) rep(j, 0, n) g[i][j] = 0;
		
		rep(i, 0, k) add(a[i], i + 1);

		auto [val, largest] = q.top(); q.pop();
		
		for (int i = 0; i < n; i += 2) {
			for (int j = 1; j < n; j += 2) {
				assert(val);

				g[i][j] = largest;
				--val;

				if (val == 0) {
					if (q.empty()) return 1;
					tie(val, largest) = q.top();
					q.pop();
				}
			}
		}

		for (int i = 0; i < n; i += 2) {		
			for (int j = 0; j < n; j += 2) {
				if (val == 0) break;

				g[i][j] = largest;
				--val;
			}
		}
		
		add(val, largest);

		rep(i, 0, n) {
			for (int j = 0; j < n; j += 2) {
				if (q.empty()) return 1;

				if (g[i][j] != 0) continue;

				auto [f, v] = q.top(); q.pop();
				if (!fine(i, j, v)) return 0;

				g[i][j] = v;
				add(--f, v);
			}
		}

		return q.empty();
	};

	int l = 0, r = X;
	
	while (r - l > 1) {
		int m = (l + r) / 2;
		(ok(m) ? r : l) = m;
	}
	
	ok(r);
	
	cout << r << '\n';
	rep(i, 0, r) {
		rep(j, 0, r) cout << g[i][j] << ' ';
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}