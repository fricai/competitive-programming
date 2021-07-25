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

const int X = 2e5 + 10;

bool solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	if (find(all(a), 0) != end(a))
		return true;
	sort(all(a));
	if (unique(all(a)) != end(a))
		return true;
	rep(S, 0, 1 << n) {
		for (int T = S; ; --T &= S) {
			int cur = 0;
			rep(i, 0, n)
				if (T >> i & 1)
					cur += a[i];
				else if (S >> i & 1)
					cur -= a[i];
			rep(i, 0, n)
				if (~S >> i & 1)
					if (a[i] == cur)
						return true;
			if (T == 0) break;
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}