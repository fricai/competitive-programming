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

const int N = 1 << 17;
int n;
bool a[N], b[N];

vector<int> solve() {
	cin >> n;
	rep(i, 0, n) {
		char c; cin >> c; c -= '0';
		a[i] = c;
	}
	rep(i, 0, n) {
		char c; cin >> c; c -= '0';
		b[i] = c;
	}

	vector<int> op;
	for (int i = n - 1; 0 <= i; --i) {
		if (a[i] == b[i]) continue;
		if (b[i] == a[0]) op.eb(0);
		op.eb(i);
		for (int j = 0; j < i - j; ++j)
			swap(a[j], a[i - j]);
		for (int j = 0; j <= i; ++j)
			a[j] = !a[j];
	}
	return op;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		auto v = solve();
		cout << sz(v) << ' ';
		trav(x, v) cout << x + 1 << ' ';
		cout << '\n';
	}
}