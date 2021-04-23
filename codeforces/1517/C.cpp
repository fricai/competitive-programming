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

const int N = 1 << 9;
int g[N][N];
int target;
int cur;
int n;

void dfs(int x, int y) {
	if (x < 0 || y == n || cur == target || g[x][y]) return;
	++cur; g[x][y] = target;
	dfs(x - 1, y);
	dfs(x, y + 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	vector<int> p(n);
	for (auto &x : p) cin >> x;
	rep(i, 0, n) {
		cur = 0;
		target = p[i];
		dfs(i, i);
	}
	
	rep(i, 0, n) {
		rep(j, 0, i + 1) cout << g[j][i] << ' ';
		cout << '\n';
	}
}