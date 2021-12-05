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

	int h, w, n; cin >> h >> w >> n;
	vector<int> a(n), b(n);
	rep(i, 0, n) cin >> a[i] >> b[i];

	auto compress = [&](vector<int> &a) {
		auto cmp = a;
		sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));
		for (auto &x : a)
			x = lower_bound(all(cmp), x) - begin(cmp);
	};

	compress(a);
	compress(b);
	rep(i, 0, n) cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
}
