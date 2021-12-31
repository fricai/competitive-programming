#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, a, b; cin >> n >> a >> b;
	if (a + b > n - 2 || abs(a - b) > 1)
		return cout << "-1\n", void();
	bool flip = false;
	if (a > b) swap(a, b), flip = true;

	// a <= b
	vector<int> v(n);
	iota(all(v), 0);

	if (a == b) {
		int j = 0;
		for (int i = 0; j < b + 1; i += 2)
			v[i] = j++;
		for (int i = 1, k = 0; k < a; ++k, i += 2)
			v[i] = j++;
	} else {
		assert(a == b - 1);
		int j = 0;
		for (int i = 1; j < b; i += 2)
			v[i] = j++;
		for (int i = 0, k = 0; k < b; i += 2, ++k)
			v[i] = j++;
	}

	if (flip) {
		cerr << "ahoy\n";
		for (auto &x : v)
			x = n - x - 1;
	}

	for (auto x : v)
		cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
