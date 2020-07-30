#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 7;
vector<int> g[N];
int col[N];
bool out[N];
int cnt = 0;

bool dfs(int u, int c) {
	if (col[u]) return col[u] == c;
	++cnt; col[u] = c;
	trav(v, g[u]) if (!dfs(v, -c)) return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v); g[v].eb(u);
	}

	int odd_chains = 0, ans = 0;
	rep(u, 0, n) {
		if (col[u]) continue;
		cnt = 0;
		if (dfs(u, 1)) {
			if (cnt & 1) ++odd_chains;
		} else ++ans;
	}

	cout << ans + (odd_chains & 1);
}