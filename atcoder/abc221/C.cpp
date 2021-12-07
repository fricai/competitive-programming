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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> v;
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
	}

	int k = sz(v);

	ll ans = 0;
	rep(S, 0, 1 << k) {
		vector<int> l[2];
		per(j, 0, k)
			l[S >> j & 1].push_back(v[j]);
		sort(rall(l[0]));
		sort(rall(l[1]));

		if (l[0].empty() || l[0][0] == 0 || l[1].empty() || l[1][0] == 0)
			continue;

		ll a = 0, b = 0;
		for (auto x : l[0])
			a = 10 * a + x;
		for (auto x : l[1])
			b = 10 * b + x;

		uax(ans, a * b);
	}

	cout << ans << '\n';
}
