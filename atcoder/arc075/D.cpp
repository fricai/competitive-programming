#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1.5e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	ll a, b; cin >> a >> b; a -= b;
	vector<ll> h(n); for (auto &x : h) cin >> x;
	sort(all(h));

	auto f = [&](ll k) {
		auto g = h;
		for (auto &z : g) z -= k * b;
		for (auto z : g)
			if (z > 0)
				k -= (z + a - 1) / a;
		return k >= 0;
	};
	
	int l = 0, r = inf;
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		(f(m) ? r : l) = m;
	}
	cout << r;
}