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

const int N = 1 << 19;
int a[N], L[N], R[N], ord[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		L[i] = i - 1;
		R[i] = i + 1;
		ord[i - 1] = i;
	}

	sort(ord, ord + n, [&](int i, int j) { return a[i] < a[j]; });
	ll ans = 0;
	for (int j = 0, l = 1, r = n; j + 2 < n; ++j) {
		int i = ord[j];
		if (i == l) { ans += a[i]; l = R[l]; continue; }
		if (i == r) { ans += a[i]; r = L[r]; continue; }
		ans += min(a[L[i]], a[R[i]]);
		R[L[i]] = R[i];
		L[R[i]] = L[i];
	}
	cout << ans;
}