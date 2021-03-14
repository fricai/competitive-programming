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

const int N = 1 << 18;
int b[N + N], inv[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) { int x; cin >> x; }
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		inv[b[i]] = i;
	}
	bool no = false;
	int steps = 0, l = 0;
	for (int r = n, cur = 1, pre = 0; cur <= n; ++cur) {
		if (inv[cur] <= l) {
			b[++r] = cur;
			inv[cur] = r;
			++l; ++steps;
		} else if (inv[cur] <= pre) {
			no = 1;
			break;			
		}
		pre = inv[cur];
	}

	if (!no && inv[1] > l) return cout << steps, 0;
	for (int i = 1; i <= n; ++i) inv[i] = 0;
	for (int i = 1; i <= n; ++i) inv[b[i]] = i;

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ckmax(ans, inv[i] + n - i + 1);
	cout << ans;
}