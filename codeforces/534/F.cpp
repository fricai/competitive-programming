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

const int N = 5, M = 20, K = M / 2 + 1;
int a[N], b[M];

short vis[M][1 << N][K * K * K * K * K];
vector<int> T[N];
int n, m;
char g[N][M + 1];

short recur(int S, int j, int I) {
	if (j == m) {
		rep(i, 0, n) {
			if (I % K != a[i]) return -1;
			I /= K;
		}
		return +1;
	}

	if (!vis[j][S][I]) {
		for (auto X : T[b[j]]) {
			int J = 0, Y = X & ~S;
			per(i, 0, n) {
				J *= K;
				J += Y >> i & 1;
			}
			J += I;
			if (recur(X, j + 1, J) > 0) {
				rep(i, 0, n) g[i][j] = X >> i & 1 ? '*' : '.';
				return vis[j][S][I] = +1;
			}
		}
		vis[j][S][I] = -1;
	}
	return vis[j][S][I];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	rep(i, 0, n) cin >> a[i];
	rep(j, 0, m) cin >> b[j];
	rep(S, 0, 1 << n) {
		bool open = false;
		int res = 0;
		rep(i, 0, n) {
			if (~S >> i & 1) open = false;
			else if (!open) {
				++res;
				open = true;
			}
		}
		T[res].push_back(S);
	}
	recur(0, 0, 0);
	rep(i, 0, n) cout << g[i] << '\n';
}