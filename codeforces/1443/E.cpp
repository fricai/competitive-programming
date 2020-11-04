#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;

vector<int> factor(ll x) {
	ll f = 1; int n = 0;
	while (f <= x) f *= ++n;

	vector<int> res(n);
	f /= n--;
	while (x != 0) {
		int k = 0;
		while (f <= x) x -= f, ++k;
		res[n] = k;
		f /= n--;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	
	
	int b = min(14, n), f = n - b;

	vector<int> bk(b);
	iota(all(bk), n - b + 1);

	ll cur = 0;
	while (q--) {
		int t; cin >> t;
		if (--t) {
			int x; cin >> x;
			cur += x;
			vector<int> z(b);
			iota(all(z), n - b + 1);
			bk =  { };
			auto t = factor(cur);
			while (sz(t) != sz(z)) t.push_back(0);
			reverse(all(t));
			for (int x : t) {
				bk.push_back(z[x]);
				z.erase(begin(z) + x);
			}
		} else {
			int l, r; cin >> l >> r;
			auto sum = [&](int i) {
				if (i < f) return 1ll * i * (i + 1) / 2;
				ll s = 0;
				rep(j, 0, i - f) s += bk[j];
				return s + 1ll * f * (f + 1) / 2;
			};
			cout << sum(r) - sum(l - 1) << '\n';
		}

		// for (int x : bk) cerr << x << ' ';
		// cerr << '\n';
	}
}