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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 19;
int a[N], b[N], u[N], v[N], w[N], idx[N];

int nxt[N];
int head(int u) { return nxt[u] < 0 ? u : nxt[u] = head(nxt[u]); }
bool join(int u, int v) {
	u = head(u); v = head(v);
	if (u == v) return false;
	return nxt[u] = v, true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m, n; cin >> m >> n;
	rep(i, 0, m) cin >> a[i];
	rep(i, 0, n) cin >> b[i];

	int e = 0;
	rep(i, 0, m) {
		int s; cin >> s;
		rep(j, 0, s) {
			u[e] = i + n;
			cin >> v[e]; --v[e];
			w[e] = a[i] + b[v[e]];
			++e;
		}
	}

	iota(idx, idx + e, 0);
	sort(idx, idx + e, [&](int x, int y) { return w[x] > w[y]; });
	ll ans = 0;
	fill(nxt, nxt + n + m, -1);
	rep(i, 0, e) if (!join(u[idx[i]], v[idx[i]])) ans += w[idx[i]];
	cout << ans;
}