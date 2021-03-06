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
int a[N], n, f[N];

int get_mex() {
	rep(i, 0, n + 2) f[i] = 0;
	rep(i, 0, n) ++f[a[i]];
	rep(i, 0, n + 2)
		if (f[i] == 0)
			return i;
	return n + 2;
}

vector<int> solve() {
	cin >> n; rep(i, 0, n) cin >> a[i];
	vector<int> op;
	while (true) { 
		int x = get_mex();
		if (n <= x) {
			bool did_stuff = false;
			rep(i, 0, n) {
				if (a[i] == i) continue;
				a[i] = n;
				op.push_back(i);
				did_stuff = 1;
				break;
			}
			if (!did_stuff) return op;
		} else {
			a[x] = x;
			op.push_back(x);
		}
	}
	return op;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		auto v = solve();
		cout << sz(v) << '\n';
		trav(x, v) cout << x + 1 << ' ';
		cout << '\n';
	}
}