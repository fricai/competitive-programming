#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

template<class T>
struct prefix_sum {
	vector<T> v;
	prefix_sum(int n) : v(n + 1, 0) { }
	void set(int u, T val) { v[u + 1] = val; }
	void init() { partial_sum(all(v), begin(v)); }
	T sum(int l, int r) { return v[r] - v[l]; }
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	string s; cin >> s;

	auto C = [&](ll x) { return x * (x - 1) / 2; };

	prefix_sum<ll> t(n), z(n);
	auto dfs = [&](const auto &self, int u) -> int {
		if (s[u] == ')') return u;

		int deg = 0, v = u + 1;
		while (v < n && s[v] != ')') {
			++deg;
			v = self(self, v) + 1;
		}

		if (v < n) {
			t.set(u, 1 + C(deg));
			z.set(u, 1);
			z.set(v, -deg);
		}
		return v;
	};

	for (int i = 0; i < n;)
		i = dfs(dfs, i) + 1;
	t.init();
	z.init();

	while (q--) {
		int type, l, r; cin >> type >> l >> r; --l;
		assert(type == 2);
		cout << t.sum(l, r) + C(z.sum(l, r)) << '\n';
	}
}
