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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<pair<int, int>> a(m), b(m);
	for (auto &[x, y] : a)
		cin >> x >> y, --x, --y;
	for (auto &[x, y] : b)
		cin >> x >> y, --x, --y;

	vector<int> ord(n);
	iota(all(ord), 0);

	auto order = [&](auto a) { return a.first < a.second ? a : pair(a.second, a.first); };
	auto tr = [&](auto a) {
		a.first = ord[a.first];
		a.second = ord[a.second];
		return order(a);
	};

	do {
		set<pair<int, int>> x, y;
		rep(e, 0, m) x.insert(order(a[e])), y.insert(tr(b[e]));
		if (x == y) return cout << "Yes\n", 0;
	} while (next_permutation(all(ord)));
	cout << "No\n";
}
