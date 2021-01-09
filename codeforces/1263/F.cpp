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

const int N = 1 << 10;
int leaves;

struct {
	int n;
	int p[N << 1], cost[N][N], deg[N << 1];
	int x[N];

	void init() {
		cin >> n;
		for (int u = 2; u <= n; ++u) cin >> p[u];
		for (int r = 1; r <= leaves; ++r) {
			cin >> x[r];

			fill(deg, deg + n + 1, 0);
			deg[1] = 1;
			for (int u = 2; u <= n; ++u) ++deg[p[u]];

			for (int l = r; l; --l) {
				cost[l][r] = cost[l + 1][r];

				int v = x[l];
				while (!deg[v]) {
					v = p[v];
					++cost[l][r];
					--deg[v];
				}
			}
		}
	}
} A, B;

int dp[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> leaves;
	A.init();
	B.init();
	for (int r = 1; r <= leaves; ++r)
		for (int l = 1; l <= r; ++l)
			ckmax(dp[r], dp[l - 1] + max(A.cost[l][r], B.cost[l][r]));
	
	cout << dp[leaves];
}