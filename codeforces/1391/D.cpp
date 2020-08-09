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

const int N = 1 << 20;
int g[N][4];
string tmp[N];

int ans() {
	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> tmp[i];
	if (n == 1 || m == 1) return 0;
	if (n >= 4 && m >= 4) return -1;
	if (m < n) {
		rep(i, 0, n)
			rep(j, 0, m)
				g[i][j] = tmp[i][j] - '0';
	} else {
		rep(i, 0, n)
			rep(j, 0, m)
				g[j][i] = tmp[i][j] - '0';
		swap(n, m);
	}

	assert(m <= 3);

	rep(i, 0, n) rep(j, 0, m) if (i % 2 == 0 && j % 2 == 0) g[i][j] ^= 1;

	int fin = N;
	rep(S, 0, 1 << m) {
		int ans = 0;
		rep(j, 0, m) if (S & 1 << j) g[0][j] ^= 1, ++ans;
		rep(i, 1, n) {
			int t = N;
			rep(S, 0, 1 << m) {
				int cnt = 0;
				rep(j, 0, m) if (S & 1 << j) g[i][j] ^= 1, ++cnt;
				bool flag = false;
				rep(j, 0, m) flag |= g[i][j] ^ g[0][0] ^ g[0][j] ^ g[i][0];
				if (!flag) ckmin(t, cnt);
				rep(j, 0, m) if (S & 1 << j) g[i][j] ^= 1;
			}
			ans += t;
		}
		rep(j, 0, m) if (S & 1 << j) g[0][j] ^= 1;
		ckmin(fin, ans);
	}

	return fin;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << ans();
}