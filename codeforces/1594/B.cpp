#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int M = 1e9 + 7;

void inc(int &x, int y) { x += y; if (x >= M) x -= M; }
int mul(ll x, int y) { return x * y % M; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;

		int ans = 0;
		for (int z = 1; k; z = mul(z, n), k >>= 1) {
			if (k & 1)
				inc(ans, z);
		}
		cout << ans << '\n';

	}
}
