#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<tuple<int, int, ll>> rect(n);
	for (auto &[x, y, a] : rect) cin >> x >> y >> a;
	sort(all(rect));

	auto f = [&](int y, auto b) { return real(b) * y + imag(b); };

	ll ans = 0;
	deque<complex<__int128_t>> st = {0};
	for (auto &[x, y, a] : rect) {
		while (sz(st) > 1 && f(y, st.back()) <= f(y, st[sz(st) - 2])) st.pop_back();
		ll dp = f(y, st.back()) + 1ll * x * y - a;
		ckmax(ans, dp); complex<__int128_t> cur = {-x, dp};
		while (sz(st) > 1 && 0 <= imag((cur - st[0]) * conj(st[1] - st[0]))) st.pop_front();
		st.push_front(cur);
	}
	cout << ans;
}