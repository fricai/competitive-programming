#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

vector<int> solve() {
	int n; cin >> n;
	vector<int> a(2 * n); trav(x, a) cin >> x;
	vector<bool> vis(n, false);
	vector<int> ans;
	trav(x, a) if (!vis[x]) ans.eb(x), vis[x] = true;
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		trav(x, solve()) cout << x << ' ';
		cout << '\n';
	}
}