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
int n;
ll a[N];

bool ishill(int i) {
	if (i <= 0 || i >= n - 1) return false;
	return a[i - 1] < a[i] && a[i] > a[i + 1];
}

bool isvalley(int i) {
	if (i <= 0 || i >= n - 1) return false;
	return a[i - 1] > a[i] && a[i] < a[i + 1];
}

bool yes(int i) { return ishill(i) || isvalley(i); }

int cnt(int i, int j) {
	int res = 0;
	for (int k = i; k <= j; ++k) res += yes(k);
	return res;
}

int solve() {
	cin >> n;
	rep(i, 0, n) cin >> a[i];

	int cur = 0;
	rep(i, 0, n) cur += yes(i);

	int ans = cur;
	rep(i, 1, n - 1) {
		int x = a[i], del = cnt(i - 2, i + 2);

		a[i] = (a[i - 1] + a[i + 1]) / 2;
		ckmin(ans, cur - del + cnt(i - 2, i + 2));

		a[i] = (a[i - 1] + a[i + 1] + 1) / 2;
		ckmin(ans, cur - del + cnt(i - 2, i + 2));

		a[i] = max(a[i - 1], a[i + 1]) + 1;
		ckmin(ans, cur - del + cnt(i - 2, i + 2));

		a[i] = max(a[i - 1], a[i + 1]);
		ckmin(ans, cur - del + cnt(i - 2, i + 2));

		a[i] = max(a[i - 1], a[i + 1]) - 1;
		ckmin(ans, cur - del + cnt(i - 2, i + 2));

		a[i] = min(a[i - 1], a[i + 1]) + 1;
		ckmin(ans, cur - del + cnt(i - 2, i + 2));

		
		a[i] = min(a[i - 1], a[i + 1]);
		ckmin(ans, cur - del + cnt(i - 2, i + 2));

		a[i] = min(a[i - 1], a[i + 1]) - 1;
		ckmin(ans, cur - del + cnt(i - 2, i + 2));

		a[i] = x;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}