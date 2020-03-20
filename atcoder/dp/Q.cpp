#include <algorithm>
#include <iostream>
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

constexpr int N = 1 << 18;
ll t[N << 1];
int h[N], a[N];

int n;
ll query(int l, int r) {
	ll res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ckmax(res, t[l++]);
		if (r & 1) ckmax(res, t[--r]);
	}
	return res;
}
void modify(int p, ll v) {
	for (t[p += n] = v; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	rep(i, 0, n) cin >> h[i], --h[i];
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) modify(h[i], query(0, h[i]) + a[i]);
	cout << query(0, n) << '\n';
}