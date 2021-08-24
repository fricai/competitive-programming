#include <bits/stdc++.h>
// #include <atcoder/lazysegtree>

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

int n, m;
void inc(int &x, int y) {
	x += y;
	if (x >= m) x -= m;
}

const int N = 4e6 + 10;
int t[N << 1];
void modify(int l, int r, int value) {
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) inc(t[l++], value);
		if (r & 1) inc(t[--r], value);
	}
}

int query(int p) {
	int res = 0;
	for (p += N; p > 0; p >>= 1)
		inc(res, t[p]);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	modify(1, 2, 1);

	int tot = 1;
	for (int i = 1; i <= n; ++i) {
		// modify(i, i + 1, 
		// for (int j = 2; j <= i; ++j)
		//	inc(dp[i], dp[i / j]);	
		
		if (i > 1) {
			modify(i, i + 1, tot);
			inc(tot, query(i));
		}

		int cur = query(i);
		for (int r = 2; r * i <= n; ++r)
			modify(r * i, min(r * i + r, n + 1), cur);

		/*
		for (int k = 2 * i, r = 2; k <= n; k += i, ++r) {
			for (int j = k; j < k + r && j <= n; ++j)
				inc(dp[j], dp[i]);
		}
		*/
	}

	cout << query(n) << '\n';
}
