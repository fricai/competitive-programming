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
	vector<complex<ll>> ps(n);
	for (auto &p : ps) {
		int x, y; cin >> x >> y;
		p = {x, y};
	}

	int ans = 0;
	rep(i, 0, n) {
		rep(j, 0, i) {
			rep(k, 0, j) {
				auto b = ps[k] - ps[i];
				auto c = ps[j] - ps[i];
				ans += b * conj(c) != c * conj(b);
			}
		}
	}
	cout << ans << '\n';
}
