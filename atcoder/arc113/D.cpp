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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;

	if (n == 1 || m == 1) {
		cout << mint(k).pow(max(n, m)).val() << '\n';
		return 0;
	}

	mint ans = 0;

	for (mint x = 1, en = k + 1; x != en; ++x) {
		ans += (x.pow(n) - (x - 1).pow(n)) * (k - x + 1).pow(m);
	}
	cout << ans.val() << '\n';
}
