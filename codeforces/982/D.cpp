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
int a[N], cmp[N], p[N];
int L[N], R[N], f[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i], cmp[i] = a[i];
	sort(cmp, cmp + n);
	rep(i, 0, n) a[i] = lb(cmp, cmp + n, a[i]) - cmp;
	rep(i, 0, n) p[a[i]] = i;

	rep(i, 0, n) L[i] = i - 1, R[i] = i + 1;

	int ans = -1, mx_loc = 0, cur = 0;
	rep(k, 0, n) {
		int i = p[k];
		int pre = i - L[i] - 1;
		int nxt = R[i] - i - 1;
		if (L[i] != -1) R[L[i]] = R[i];
		if (R[i] != n) L[R[i]] = L[i];
		if (pre != 0) --f[pre], --cur;
		if (nxt != 0) --f[nxt], --cur;
		if (++f[pre + nxt + 1] == ++cur && ckmax(mx_loc, cur)) ans = k;
	}

	cout << cmp[ans] + 1;
}