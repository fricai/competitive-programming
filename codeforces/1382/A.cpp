#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 10;
int c[N], d[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		rep(i, 0, N) c[i] = d[i] = 0;

		int n, m; cin >> n >> m;
		rep(i, 0, n) {
			int x; cin >> x;
			c[x]++;
		}
		rep(i, 0, m) {
			int x; cin >> x;
			d[x]++;
		}
		bool f = false;
		rep(i, 0, N) {
			if (c[i] && d[i]) {
				cout << "YES\n" << 1 << ' ' << i << '\n';
				f = true;
				break;
			}
		}
		if (!f) cout << "NO\n";
	}
}