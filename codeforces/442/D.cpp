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

const int N = 1 << 20;
int p[N], dp[N], mx1[N], mx2[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n + 1; ++i) mx2[i] = mx1[i] = -1;

	for (int i = 2; i <= n + 1; ++i) {
		cin >> p[i];

		int u = i;
		bool changed = true;
		while (u != 1 && changed) {
			int z = dp[u], v = p[u];
			if (mx1[v] <= z) mx2[v] = mx1[v], mx1[v] = z;
			else if (mx2[v] < z) mx2[v] = z;
			changed = ckmax(dp[v], max(1 + mx2[v], mx1[v]));
			u = v;
		}
		cout << 1 + mx1[1] << ' ';
	}

}