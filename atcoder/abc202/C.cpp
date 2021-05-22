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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n), b(n), c(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	for (auto &x : c) cin >> x, --x;

	auto cmp = a;
	sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));

	vector<int> f(sz(cmp));
	for (auto &x : a)
		++f[lower_bound(all(cmp), x) - begin(cmp)];

	ll cnt = 0;
	for (auto i : c) {
		int j = lower_bound(all(cmp), b[i]) - begin(cmp);
		if (cmp[j] == b[i]) cnt += f[j];
	}
	cout << cnt << '\n';
}