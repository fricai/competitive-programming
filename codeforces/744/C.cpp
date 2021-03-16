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

const int N = 16;
const int inf = 1e9;
int dp[2][N * N + 1][1 << N];
int c[N], r[N], b[N];
bool vis[2][N * N + 1][1 << N];

int n;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	int R = 0, B = 0;
	rep(i, 0, n) {
		char ch;
		cin >> ch >> r[i] >> b[i];
		c[i] = ch == 'R';
		if (r[i] > n) R += r[i] - n, r[i] = n;
		if (b[i] > n) B += b[i] - n, b[i] = n;
	}

	int X = n * n;
	rep(b, 0, 2)
		for (int c = 0; c <= n * n; ++c)
			rep(S, 0, 1 << n)
				dp[b][c][S] = inf;

	queue<tuple<int, int, bool>> que;
	if (R > B) {
		dp[0][min(R - B, X)][0] = R + n;
		que.push({0, min(R - B, X), 0});
	}
	else {
		dp[1][min(B - R, X)][0] = B + n;
		que.push({0, min(B - R, X), 1});
	}

	while (!que.empty()) {
		auto [S, x, g] = que.front(); que.pop();

		if (vis[g][x][S]) continue;
		vis[g][x][S] = 1;

		int rc = 0, bc = 0;
		rep(i, 0, n) if (S >> i & 1) rc += c[i], bc += !c[i];

		rep(i, 0, n) {
			if (S >> i & 1) continue;
			int p = max(0, r[i] - rc), q = max(0, b[i] - bc);

			auto add = [&](bool c, int cost, int T, int del) {
				ckmin(dp[c][cost][T], dp[g][x][S] + del);
				que.push({T, cost, c});
			};
			
			if (g) {
				if (p <= x + q)
					add(1, min(X, x + q - p), S | 1 << i, q);
				else
					add(0, min(X, p - x - q), S | 1 << i, p - x);
			} else {
				if (q <= x + p)
					add(0, min(X, x + p - q), S | 1 << i, p);
				else
					add(1, min(X, q - x - p), S | 1 << i, q - x);
			}
		}
	}

	int ans = inf;
	rep(b, 0, 2) rep(j, 0, X + 1) ckmin(ans, dp[b][j][(1 << n) - 1]);
	cout << ans;
}