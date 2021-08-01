#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; cin >> n >> m;
	vector<int> f(n);
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		++f[min(u, v)];
	}

	int ans = 0;
	rep(u, 0, n) ans += f[u] == 0;
	
	int q; cin >> q;
	while (q--) {
		int type; cin >> type;

		if (type == 3) {
			cout << ans << '\n';
		} else {
			int u, v; cin >> u >> v; --u; --v;
			int x = min(u, v);
			if (type == 1) {
				if (f[x] == 0) --ans;
				++f[x];
			} else {
				--f[x];
				if (f[x] == 0) ++ans;
			}
		}
	}
}