#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, m; cin >> n >> m;
	vector<bool> center(n, true);
	rep(e, 0, m) {
		int a, b, c; cin >> a >> b >> c;
		center[b - 1] = false;
	}
	rep(u, 0, n) {
		if (!center[u])
			continue;
		rep(v, 0, n)
			if (u != v)
				cout << u + 1 << ' ' << v + 1 << '\n';
		return;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
