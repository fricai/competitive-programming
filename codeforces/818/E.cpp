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

int k;
int mul(ll x, int y) { return x * y % k; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	vector<int> t(n + n);
	rep(i, 0, n) t[i + n] = a[i] % k;
	per(i, 1, n) t[i] = mul(t[i << 1], t[i << 1|1]);
	auto query = [&](int l, int r) {
		int res = 1;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = mul(res, t[l++]);
			if (r & 1) res = mul(res, t[--r]);
		}
		return res;
	};

	ll ans = 0;
	for (int l = 0, r = 0; l < n; ++l) {
		while (r < n && query(l, r + 1) != 0)
			++r;
		if (r != n)
			ans += n - r;
	}
	cout << ans << '\n';
}
