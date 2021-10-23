#include <bits/stdc++.h>
#include <atcoder/modint>

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

using mint = atcoder::modint998244353;

using P = pair<ll, ll>;
using line = tuple<ll, ll, ll>;
line get_line(P p, P q) {
	// 1 -> p, 2 -> q
	ll b = q.first - p.first;
	ll a = -(q.second - p.second);
	ll c = p.first * q.second - p.second * q.first;
	ll g = gcd(gcd(a, b), c);
	a /= g;
	b /= g;
	c /= g;
	assert(a != 0 || b != 0);
	if (a < 0 || (a == 0 && b < 0)) {
		a = -a;
		b = -b;
		c = -c;
	}
	return {a, b, c};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<P> p(n);
	for (auto &[x, y] : p) {
		cin >> x >> y;
	}

	map<line, vector<int>> s;
	rep(i, 0, n) {
		rep(j, 0, i) {
			auto &v = s[get_line(p[i], p[j])];
			v.push_back(i);
			v.push_back(j);
		}
	}

	mint ans = mint(2).pow(n) - 1 - n;

	for (auto [l, v] : s) {
		sort(all(v));
		v.erase(unique(all(v)), end(v));
		ans -= mint(2).pow(sz(v)) - 1 - sz(v);
	}

	cout << ans.val() << '\n';
}
