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

const int inf = 1.2e9;

void solve() {
	int n, m, x; cin >> n >> m >> x;

	priority_queue<pair<int, int>> q;

	rep(j, 0, m) q.push({0, j + 1});
	
	cout << "YES\n";
	rep(i, 0, n) {
		int h; cin >> h;
		auto [u, j] = q.top(); q.pop();
		u -= h;
		q.push({u, j});
		cout << j << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}