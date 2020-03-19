#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)

using ll = int64_t;
using ld = long double;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr ll inf = 2e18;
constexpr int M = 1e9 + 7;


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, K; cin >> n >> K;
	int a[n]; rep(i, 0, n) cin >> a[i];
	bool dp[K + 1] = {0};
	rep(k, 1, K + 1) {
		dp[k] = 0;
		rep(i, 0, n) {
			if (a[i] > k) break;
			if (!dp[k - a[i]]) {
				dp[k] = true;
				break;
			}
		}
	}
	cout << (dp[K] ? "First" : "Second");
}