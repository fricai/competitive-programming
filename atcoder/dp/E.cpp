#include <algorithm>
#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr ll inf = 2e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w, V = 1; cin >> n >> w;
	ll v[n], c[n];
	rep(i, 0, n) cin >> c[i] >> v[i], V += v[i];
	ll dp[V] = {0};  rep(x, 1, V) dp[x] = inf;
	rep(i, 0, n) per(x, v[i], V) ckmin(dp[x], dp[x - v[i]] + c[i]);
	per(x, 0, V) if (dp[x] <= w) return cout << x, 0;
}