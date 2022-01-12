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


	vector<int> stk;
	vector<int> nxt(n, -1);
	rep(i, 0, n) {
		if (s[i] == '(') stk.push_back(i);
		if (s[i] == ')') {
			if (stk.empty()) continue;
			nxt[stk.back()] = i;
			stk.pop_back();
		}
	}

	auto C = [&](ll x) { return x * (x - 1) / 2; };

	vector<int> dep(n, -1);
	vector<ll> sub(n);
	auto dfs = [&](const auto &self, int u) -> void {
		assert(~nxt[u]);
		ll deg = 0;
		sub[u] = 1;
		for (int v = u + 1; v < nxt[u]; v = nxt[v] + 1) {
			dep[v] = dep[u] + 1;
			self(self, v);
			sub[u] += sub[v];
			++deg;
		}
		sub[u] += C(deg);
	};

	for (int i = 0; i < n; ++i) {
		if (~nxt[i]) {
			dep[i] = 0;
			dfs(dfs, i);
			i = nxt[i];
		}
	}

	/*
	rep(i, 0, n) cerr << dep[i] << ' ';
	cerr << '\n';
	*/

	vector<vector<int>> lev(n);
	rep(i, 0, n) if (~dep[i]) lev[dep[i]].push_back(i);

	vector<vector<ll>> sum(n);
	rep(d, 0, n) {
		sum[d].resize(sz(lev[d]) + 1);
		rep(i, 0, sz(lev[d])) sum[d][i + 1] = sum[d][i] + sub[lev[d][i]];
	}

	/*
	rep(u, 0, n) cerr << sub[u] << ' ';
	cerr << '\n';
	*/

	while (q--) {
		int t, l, r; cin >> t >> l >> r; --l;
		assert(t == 2);

		int d = dep[l];
		assert(~d);
		int x = lower_bound(all(lev[d]), l) - begin(lev[d]);
		int y = lower_bound(all(lev[d]), r) - begin(lev[d]);

		cout << (sum[d][y] - sum[d][x]) + C(y - x) << '\n';
	}
}
