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

const int N = 1 << 13;
int nxt[N];
int head(int u) { return nxt[u] < 0 ? u : nxt[u] = head(nxt[u]); }

void join(int u, int v) {
	u = head(u); v = head(v);
	if (u == v) return;
	assert(u < v);
	nxt[u] = v;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> s(n);
		for (auto &x : s) cin >> x;

		set<int> not_one = {n};
		rep(i, 0, n) if (s[i] != 1) not_one.insert(i);

		ll ans = 0;
		fill_n(nxt, n, -1);

		rep(i, 0, n) {
			if (i + s[i] > n) {
				ans += s[i] - (n - i);
				s[i] = n - i;
				assert(s[i] > 0);
			}

			while (s[i] != 1) {
				++ans;
				int cur = i;
				while (cur < n) {
					if (s[cur] > 1) {
						int nxt = cur + s[cur];
						--s[cur];
						if (s[cur] == 1) not_one.erase(cur);
						cur = nxt;
					} else cur = *not_one.lower_bound(cur);
				}
			}
		}

		cout << ans << '\n';
	}
}