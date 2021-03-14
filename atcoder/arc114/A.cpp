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

const ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> res;
	for (int d = 2; d <= 50; ++d) {
		bool prime = true;
		for (int k = 2; k < d; ++k)
			if (d % k == 0) prime = false;
		if (prime) res.push_back(d);
	}

	int n; cin >> n;
	vector<int> x(n);
	for (auto &y : x) cin >> y;

	ll mn = inf;
	rep(S, 0, 1 << sz(res)) {
		ll prod = 1;
		rep(i, 0, sz(res))
			if (S >> i & 1)
				prod *= res[i];
		bool valid = true;
		for (auto y : x)
			if (gcd(y, prod) == 1) valid = false;
		if (valid) ckmin(mn, prod);
	}
	cout << mn;
}