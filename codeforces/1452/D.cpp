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

const int M = (119 << 23) + 1, N = 1 << 18;
ll g[N];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n; cin >> n;
	g[0] = 1;

	ll odd = 0, even = 1, p = (M + 1) / 2, q = 1;
	for (int i = 1; i <= n; ++i) {
		if (i & 1) {
			g[i] = even;
			odd += g[i];
			odd %= M;
		} else {
			g[i] = odd;
			even += g[i];
			even %= M;
		}
		q = p * q % M;
	}
	cout << g[n] * q % M;
}