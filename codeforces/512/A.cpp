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

const int N = 1 << 7, A = 26;
string s[N];
vector<int> g[A];
int indeg[A];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> s[i];
	rep(i, 1, n) {
		int r = min(sz(s[i - 1]), sz(s[i])), j = 0;
		while (j < r && s[i][j] == s[i - 1][j]) ++j;
		if (j == sz(s[i])) return cout << "Impossible", 0;
		if (j == sz(s[i - 1])) continue;
		g[s[i - 1][j] - 'a'].push_back(s[i][j] - 'a');
	}
	rep(u, 0, A) for (auto v : g[u]) ++indeg[v];

	queue<int> q;
	rep(u, 0, A) if (indeg[u] == 0) q.push(u);
	string t;
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		t += char(u + 'a');
		for (auto v : g[u]) if (--indeg[v] == 0) q.push(v);
	}
	if (sz(t) < A) return cout << "Impossible", 0;
	cout << t << '\n';
}