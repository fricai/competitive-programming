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

const int N = 1 << 9;
int g[N][N];
pair<int, int> pos[N * N];


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		rep(i, 0, n) {
			rep(j, 0, m) {
				int x; cin >> x;
				pos[x] = {0, j};
			}
		}

		rep(j, 0, m) {
			rep(i, 0, n) {
				int x; cin >> x;
				pos[x].first = i;
			}
		}
		for (int x = 1; x <= n * m; ++x) g[pos[x].first][pos[x].second] = x;
		rep(i, 0, n) {
			rep(j, 0, m) cout << g[i][j] << ' ';
			cout << '\n';
		}
	}
}