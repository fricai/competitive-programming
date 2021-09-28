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

int solve() {
	int n, d; cin >> n >> d;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	reverse(all(a));

	int g = gcd(d, n);
	rep(i, 0, g) {
		int x = a[i];
		for (int j = (i + d) % n; j != i; (j += d) %= n) {
			x &= a[j];
		}
		if (x != 0)
			return -1;
	}

	int ans = 0;
	rep(i, 0, g) {
		vector<int> v = {a[i]};
		for (int j = (i + d) % n; j != i; (j += d) %= n) {
			v.push_back(a[j]);
		}
		auto s = v;
		for (auto x : s)
			v.push_back(x);

		for (int l = 0, r = 0; l < sz(v); l = r) {
			if (v[l] == 0) {
				++r;
				continue;
			}

			while (r < sz(v) && v[r] == 1)
				++r;
			uax(ans, r - l);
		}
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
