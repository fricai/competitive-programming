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

constexpr int M = 1e9 + 7;

using dp = array<int, 6>;

const map<string, int> num = {{"white", 0}, {"yellow", 1}, {"green", 2}, {"blue", 3}, {"red", 4}, {"orange", 5}};

int mul(ll x, int y) { return x * y % M; }
void inc(int &x, int y) { x += y; if (x >= M) x -= M; }

dp operator*(dp a, dp b) {
	dp c;
	rep(i, 0, 6) {
		int s = 0, t = 0;
		rep(j, 0, 6) {
			if ((i ^ j) > 1) {
				inc(s, a[j]);
				inc(t, b[j]);
			}
		}
		c[i] = mul(s, t);
	}
	return c;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n; cin >> k >> n;

	vector<vector<pair<ll, int>>> c(k);
	rep(i, 0, n) {
		ll v; string s;
		cin >> v >> s;
		c[63 - __builtin_clzll(v)].emplace_back(v, num.at(s));
	}

	map<ll, dp> a;
	for (auto [v, s] : c[k - 1]) {
		a[v] = {0, 0, 0, 0, 0, 0};
		a[v][s] = 1;
	}

	dp f = {1, 1, 1, 1, 1, 1};

	per(i, 0, k - 1) {
		map<ll, dp> b;
		for (auto [v, x] : a) {
			auto it = a.find(v ^ 1);
			if (it == end(a))
				b[v >> 1] = x * f;
			else if (v & 1)
				b[v >> 1] = x * it->second;
		}

		f = f * f;

		for (auto [v, s] : c[i]) {
			auto it = b.find(v);
			if (it == end(b)) {
				tie(it, ignore) = b.insert({v, f});
			}
			rep(i, 0, 6)
				if (i != s)
					(it->second)[i] = 0;
		}

		a = move(b);
	}

	int ans = 0;
	for (auto x : a[1])
		inc(ans, x);
	cout << ans << '\n';
}
