#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 7;
int w[N];
bool vis[N];

int solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> w[i];

	int mx = 0;
	rep(s, 0, N) {
		int k = 0;
		rep(i, 0, n) vis[i] = false;
		rep(i, 0, n)
			rep(j, i + 1, n) {
				if (vis[i] || vis[j]) continue;
				if (w[i] + w[j] == s) {
					++k;
					vis[i] = vis[j] = true;
				}
			}
		ckmax(mx, k);
	}
	return mx;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}