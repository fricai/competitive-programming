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

const int inf = 2e9;

bool solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	ll cur = 1;
	for (int i = 0; i < n; ++i) {
		if (cur < inf) cur = lcm(cur, i + 2);
		if (a[i] % cur == 0)
			return false;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}
