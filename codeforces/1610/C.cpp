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

int solve() {
	int n; cin >> n;

	vector<int> a(n), b(n);
	rep(i, 0, n) {
		cin >> a[i] >> b[i];
	}

	auto f = [&](int x) -> bool { // true if we can build a party of size x
		int cur = 0;
		rep(i, 0, n) {
			if (b[i] >= cur && a[i] + cur + 1 >= x) {
				++cur;
			}
		}
		return cur >= x;
	};

	int l = 1, r = n + 1; // possible to build a party of size 1, impossible of size n + 1
	while (r - l > 1) {
		int m = (l + r) / 2;
		(f(m) ? l : r) = m;
	}
	assert(l <= n);
	return l;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
