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

const int N = 1 << 17, A = 26;
bool f[A][A];
bool vis[A];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		for (auto c : s) {
			for (auto d : s) {
				f[c - 'a'][d - 'a'] = 1;
			}
		}
	}
	rep(k, 0, A) rep(i, 0, A) rep(j, 0, A) f[i][j] |= f[i][k] && f[k][j];

	int cnt = 0;
	rep(i, 0, A) {
		if (!f[i][i]) continue;
		if (vis[i]) continue;
		++cnt;
		rep(j, 0, A) if (f[i][j]) vis[j] = true;
	}

	cout << cnt;
}