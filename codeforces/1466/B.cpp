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

const int N = 1 << 17;
int x[N], f[2 * N];

int solve() {
	int n; cin >> n;

	int cnt = 0;
	rep(i, 0, 2 * n + 2) f[i] = 0;
	rep(i, 0, n) cin >> x[i], ++f[x[i]];
	rep(i, 0, 2 * n + 2) {
		if (f[i] > 1) {
			--f[i];
			++f[i + 1];
		}
		if (f[i]) ++cnt;
	}
	return cnt;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}