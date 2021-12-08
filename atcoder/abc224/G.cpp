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

template<class F>
int ternSearch(int a, int b, F f) {
	assert(a <= b);
	while (b - a >= 5) {
		int mid = (a + b) / 2;
		if (f(mid) < f(mid+1)) a = mid; // (A)
		else b = mid+1;
	}
	rep(i,a+1,b+1) if (f(a) < f(i)) a = i; // (B)
	return a;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, s, t, a, b; cin >> n >> s >> t >> a >> b;

	auto f = [&](int r) -> ld {
		assert(1 <= r && r <= t);
		auto x = ld(b) * n / r + ld(a) * (r - 1) / 2;
		if (s > t) return -x;
		return -min(ld(a) * (t - s), x);

	};

	int r = ternSearch(1, t, f);

	cout << fixed << setprecision(10);
	cout << -f(r) << '\n';
}
