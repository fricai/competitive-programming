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

constexpr int X = 1e5 + 10;
int t[X][2];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n; ll l; cin >> n >> l;

	int nodes = 1;
	for (int _ = 0; _ < n; ++_) {
		string s; cin >> s;

		int root = 0;
		for (int i = 0; i < sz(s); ++i) {
			int &nxt = t[root][s[i] - '0'];
			if (nxt == 0) nxt = nodes++;
			root = nxt;
		}
	}

	ll g = 0;
	auto dfs = [&](const auto &self, int u, ll h) -> void {
		if ((t[u][0] != 0) ^ (t[u][1] != 0)) {
			g ^= h&-h;
		}
		for (auto b : {0, 1})
			if (t[u][b] != 0)
				self(self, t[u][b], h - 1);
	};
	dfs(dfs, 0, l);
	cout << (g ? "Alice" : "Bob") << '\n';
}
