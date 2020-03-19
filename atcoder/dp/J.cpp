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

constexpr int N = 301;
ld E[N][N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c[3] = {0, 0, 0}; cin >> n;
	rep(i, 0, n) { int a; cin >> a; ++c[--a]; }
	rep(k, 0, n + 1)
		rep(j, 0, n + 1)
			rep(i, 0, n + 1) {
				int s = i + j + k;
				if (n < s) break;
				if (s == 0) continue;
				auto &x = E[i][j][k];
				x = n;
				if (i) x += i * E[i - 1][j][k];
				if (j) x += j * E[i + 1][j - 1][k];
				if (k) x += k * E[i][j + 1][k - 1];
				x /= s;
			}
	cout << fixed << setprecision(10) << E[c[0]][c[1]][c[2]];
}