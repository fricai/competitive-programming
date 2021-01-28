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
ll d[2 * N], s[N], b[N];

bool solve() {
	int n; cin >> n;
	for (int i = 1; i <= 2 * n; ++i) cin >> d[i];
	for (int i = 1; i <= 2 * n; ++i) {
		if (d[i] & 1) return false;
		d[i] /= 2;
	}
	sort(d + 1, d + 2 * n + 1);

	for (int i = 1, j = 2; j <= 2 * n; i += 2, j += 2)
		if (d[i] != d[j]) return false;
	for (int i = 1, j = 1; i <= n; ++i, j += 2) s[i] = d[j];

	if (s[n] % n) return false;
	b[n] = s[n] / n;
	for (int k = n - 1; k > 0; --k) {
		if (s[k + 1] == s[k]) return false;
		if (s[k + 1] % k != s[k] % k) return false;
		b[k] = b[k + 1] - (s[k + 1] - s[k]) / k;
	}
	for (int k = 1; k <= n; ++k) if (b[k] <= 0) return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}