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

const int N = 1 << 19, inf = 2e9;
int a[N], b[N], st[N], dead[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	rep(i, 0, n) cin >> a[i], a[i] -= i;
	for (int i = 1; i <= k; ++i) cin >> b[i], dead[--b[i]] = true;
	rep(i, 1, k) if (a[b[i]] > a[b[i + 1]]) return cout << "-1\n", 0;

	int p = -1, lst = -1;
	rep(i, 0, n) {
		if (p < 0 || st[p] <= a[i]) {
			st[++p] = a[i];
			if (dead[i]) lst = p;
		} else {
			int z = ub(st, st + p + 1, a[i]) - st;
			if (z <= lst) continue;
			st[z] = a[i];
			if (dead[i]) lst = p = z;
		}
	}
	cout << n - p - 1 << '\n';
}