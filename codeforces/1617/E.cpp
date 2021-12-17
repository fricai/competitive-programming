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

int parent(int x) {
	if ((x & (x - 1)) == 0)
		return 0;
	int j = 32 - __builtin_clz(x);
	return (1ll << j) - x;
}

vector<int> ancestors(int x) {
	vector<int> res;
	while (x != 0) {
		res.push_back(x);
		x = parent(x);
	}
	reverse(all(res));
	return res;
}

int dist(int u, int v) {
	auto a = ancestors(u);
	auto b = ancestors(v);
	int i = 0;
	while (i < sz(a) && i < sz(b) && a[i] == b[i]) ++i;
	return (sz(a) - i) + (sz(b) - i);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	auto furthest = [&](int x) {
		int s = x, d = 0;
		for (int i = 0; i < n; ++i)
			if (uax(d, dist(a[x], a[i])))
				s = i;
		return pair(s, d);
	};

	int x = furthest(0).first;
	auto [y, d] = furthest(x);
	cout << x + 1 << ' ' << y + 1 << ' ' << d << '\n';
}
