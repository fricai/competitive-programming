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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 19;
int d[N];
ll z[N];
bool ans[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, dest; cin >> n >> dest; rep(i, 0, n) cin >> d[i];

	z[n] = 1;
	per(i, 0, n) {
		if (z[i + 1] <= d[i] / 2) z[i] = z[i + 1];
		else z[i] = z[i + 1] + d[i];
	}

	for (int i = 0, cur = 0; i < n; ++i) {
		if (z[i + 1] <= abs(dest - cur)) ans[i] = 1;
		if (cur > dest) {
			if (abs(dest - cur) > abs(dest - (cur - d[i])))
				cur -= d[i];
		} else {
			if (abs(dest - cur) > abs(dest - (cur + d[i])))
				cur += d[i];
		}
		// cerr << cur << ' ';
	}
	// cerr << '\n';

	int q; cin >> q;
	while (q--) { int u; cin >> u; cout << (ans[--u] ? "YES" : "NO") << '\n'; }
}