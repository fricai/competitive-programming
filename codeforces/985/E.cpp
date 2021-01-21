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

const int N = 1 << 19;
bool t[N << 1], dp[N];
int a[N];

bool query(int l, int r) {
	bool res = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res |= t[l++];
		if (r & 1) res |= t[--r];
	}
	return res;
}

void update(int p, bool b) { for (t[p |= N] = b; p >>= 1; ) t[p] = t[p << 1] | t[p << 1|1]; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, d; cin >> n >> k >> d;
	rep(i, 0, n) cin >> a[i + 1];
	sort(a + 1, a + n + 1);

	update(0, 1);
	for (int i = 1, j = 0, r = 0, cnt = 0; i <= n; ++i) {
		while (a[i] - a[j] > d) ++j;
		update(i, query(j - 1, i - k + 1));
	}
	cout << (query(n, n + 1) ? "YES" : "NO");
}