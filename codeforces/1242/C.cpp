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

const int N = 10 << 9, K = 1 << 4, NC = K * N;
vector<int> a[K];
int k, nxt[NC], grp[NC], cmpi[NC];
bool exists[1 << K], dp[1 << K], vis[NC];
vector<int> cycle[1 << K];
map<ll, int> cmp;

void dfs(int u) {
	vis[u] = true;
	if (!nxt[u]) return;
	if (!vis[nxt[u]]) return dfs(nxt[u]);
	int visited = 1 << grp[u];
	vector<int> tmp = {u};
	if ([&]() {
		for (int v = nxt[u]; v != u; v = nxt[v]) {
			if (visited >> grp[v] & 1) return false;
			visited |= 1 << grp[v];
			tmp.push_back(v);
		}
		return true;
	}()) exists[visited] = true, cycle[visited] = move(tmp);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tot = 0; cin >> k;
	ll s = 0;
	rep(i, 0, k) {
		int n; cin >> n; a[i].resize(n);
		for (int &x : a[i]) {
			cin >> x;
			s += x;
			cmp[x] = ++tot;
			cmpi[tot] = x;
			grp[tot] = i;
		}
	}

	if (s % k != 0) return cout << "No", 0;
	s /= k;
	
	rep(i, 0, k) {
		ll y = 0;
		for (auto &x : a[i]) y += x;
		for (auto &x : a[i]) nxt[cmp[x]] = cmp[s - y + x];
	}
	for (int u = 1; u <= tot; ++u) if (!vis[u]) dfs(u);

	dp[0] = true;
	rep(S, 1, 1 << k)
		for (int T = S; T; T = (T - 1) & S)
			dp[S] |= exists[T] && dp[S ^ T];

	int S = (1 << k) - 1;
	if (!dp[S]) return cout << "No", 0;

	cout << "Yes\n";
	vector<int> res;
	while (S)
		for (int T = S; T; T = (T - 1) & S)
			if (dp[S ^ T] && exists[T]) {
				res.insert(end(res), all(cycle[T]));
				S ^= T;
				break;
			}
	sort(all(res), [&](int u, int v) { return grp[nxt[u]] < grp[nxt[v]]; });
	for (int v : res) cout << cmpi[nxt[v]] << ' ' << grp[v] + 1 << '\n';
}