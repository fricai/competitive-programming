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

const int N = 1 << 19;
const ll inf = 1e18;

int n;
int h[N], b[N];
ll dp[N], t[N << 1];

void upd(int p, ll v) {
	for (t[p += N] = v; p >>= 1; )
		t[p] = max(t[p << 1], t[p << 1|1]);
}
ll query(int l, int r) {
	ll res = -inf;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ckmax(res, t[l++]);
		if (r & 1) ckmax(res, t[--r]);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> h[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];

	fill_n(t, N << 1, -inf);

	stack<pair<int, int>> s;
	upd(0, 0);
	for (int i = 1; i <= n; ++i) {
		while (!s.empty() && s.top().second > h[i]) s.pop();
		if (!s.empty()) {
			int j = s.top().first;
			dp[i] = max(dp[j], query(j, i) + b[i]);
		} else dp[i] = query(0, i) + b[i];
		upd(i, dp[i]);
		s.push({i, h[i]});
	}
	
	cout << dp[n] << '\n';
}