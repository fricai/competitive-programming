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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	string s; cin >> s;

	auto C = [&](ll x) { return x * (x - 1) / 2; };

	vector<ll> t(n + 1), z(n + 1);
	auto dfs = [&](const auto &self, int u) -> int {
		if (s[u] == ')') return u + 1;

		int deg = 0, v = u + 1;
		while (v < n && s[v] != ')') {
			++deg;
			v = self(self, v);
		}

		if (v < n) {
			t[u + 1] = 1 + C(deg);
			z[u + 1] = 1;
			z[v + 1] = -deg;
		}
		return v + 1;
	};

	for (int i = 0; i < n; i = dfs(dfs, i));
	rep(i, 0, n) t[i + 1] += t[i];
	rep(i, 0, n) z[i + 1] += z[i];
	while (q--) {
		int type, l, r; cin >> type >> l >> r; --l;
		cout << (t[r] - t[l]) + C(z[r] - z[l]) << '\n';
	}
}
