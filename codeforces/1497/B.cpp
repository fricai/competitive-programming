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

const int N = 1 << 17;
int f[N];

int solve() {
	int n, m; cin >> n >> m;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
		++f[x %= m];
	}

	int ans = !!f[0];
	if (m % 2 == 0) ans += !!f[m / 2];
	for (int x = 1, y = m - 1; x < y; ++x, --y) {
		if (f[x] == 0 && f[y] == 0) continue;
		++ans;
		if (abs(f[x] - f[y]) > 1) {
			if (f[x] > f[y]) {
				f[x] -= f[y] + 1;
				ans += f[x];
			} else {
				f[y] -= f[x] + 1;
				ans += f[y];
			}
		}
	}

	for (auto x : a) f[x] = 0;
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}