#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

const int M = 1e9 + 7;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 16;
ll f[1 << N], s[1 << N];
int a[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	rep(S, 0, 1 << n)
		rep(i, 0, n)
			if (S & 1 << i)
				rep(j, i + 1, n)
					if (S & 1 << j)
						s[S] += a[i][j];
	rep(S, 0, 1 << n) {
		f[S] = s[S];
		for (int x = S; x; --x &= S)
			ckmax(f[S], s[x] + f[S & ~x]);
	}
	cout << f[(1 << n) - 1];
}