#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>

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

using mint = atcoder::modint998244353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> a(n + 1);
	rep(i, 0, n) cin >> a[i + 1];

	atcoder::fenwick_tree<mint> dp(n + 1);
	vector<int> p(n + 1, 0);
	
	dp.add(0, 1);
	for (int i = 1; i <= n; ++i) {
		int &j = p[a[i]];
		dp.add(i, dp.sum(p[a[i]], i));
		if (j != 0)
			dp.add(j, -dp.sum(j, j + 1));
		j = i;
	}

	cout << dp.sum(1, n + 1).val()  << '\n';
}
