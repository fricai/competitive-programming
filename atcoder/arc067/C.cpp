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
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using mint = atcoder::static_modint<1000000007>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	mint res = 1;
	for (int d = 2; d <= n; ++d) {
		bool isprime = true;
		for (int p = 2; p * p <= d; ++p)
			if (d % p == 0) isprime = false;
		if (!isprime) continue;
		int m = n;
		mint ret = 1;
		while (m /= d) ret += m;
		// cerr << d << ' ' << ret.val() << '\n';
		res *= ret;
	}
	cout << res.val();
}