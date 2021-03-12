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
int a[N], L[N], R[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	per(i, 0, n - 1) {
		if (a[i] > a[i + 1]) R[i] = R[i + 1] + 1;
		else R[i] = 0;
	}
	rep(i, 1, n) {
		if (a[i - 1] < a[i]) L[i] = L[i - 1] + 1;
		else L[i] = 0;
	}

	int mx = 0, cnt = 0;
	rep(i, 0, n) {
		int d = max(L[i], R[i]);
		if (ckmax(mx, d)) cnt = 1;
		else cnt += mx == d;
	}

	int ans = 0;
	rep(i, 0, n) ans += mx % 2 == 0 && L[i] == mx && R[i] == mx && cnt == 1;
	cout << ans;
}