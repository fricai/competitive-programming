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
	int i = n - 1;
	int zero = 0, cur = 0;
	bool par = 0;
	for (int bb = n - 1; 0 <= bb; --bb) {
		if ((a[i] ^ par) != b[bb]) {
			if (b[bb] == (a[zero] ^ par)) op.eb(0);
			// cerr << zero << ' ' << i << '\n';
			op.eb(bb);
			swap(zero, i);
			par ^= 1;
		}
		if (par) ++i;
		else --i;
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