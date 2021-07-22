#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int X = 1e6 + 10;
int lp[X], nxt[X];

int head(int u) { return nxt[u] < 0 ? u : nxt[u] = head(nxt[u]); }
bool join(int u, int v) {
	u = head(u); v = head(v);
	if (u == v)
		return 0;
	nxt[u] = v;
	return 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(p, 2ll, X) {
		if (lp[p]) continue;
		lp[p] = p;		
		for (auto j = p * p; j < X; j += p)
			lp[j] = p;
	}
	fill_n(nxt, X, -1);

	auto factor = [&](int x) {
		vector<int> f;
		assert(x < X);
		while (x != 1) {
			int y = lp[x];
			f.push_back(y);
			while (x % y == 0)
				x /= y;
		}
		return f;
	};

	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<vector<int>> f(n);
	rep(i, 0, n) {
		f[i] = factor(a[i]);
		rep(j, 1, sz(f[i]))
			join(f[i][j - 1], f[i][j]);
	}
	
	vector<vector<int>> tog(X);
	rep(i, 0, n) {		
		auto g = factor(1 + a[i]);
		
		vector<int> s;
		for (auto x : f[i]) s.push_back(head(x));
		for (auto x : g) s.push_back(head(x));

		sort(all(s)); s.erase(unique(all(s)), end(s));
		for (auto x : s)
			for (auto y : s)
				tog[x].push_back(y);
	}
	for (auto &v : tog) {
		sort(all(v));
		v.erase(unique(all(v)), end(v));
	}
	
	while (q--)
		cout << [&]() {
			int s, t; cin >> s >> t;
			s = head(f[s - 1][0]);
			t = head(f[t - 1][0]);
			if (s == t) return 0;
			if (binary_search(all(tog[s]), t))
				return 1;
			return 2;
		}() << '\n';
}