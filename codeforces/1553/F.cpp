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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;

struct {
	int t[N << 1];
	void activate(int p) {
		for (t[p += N] = 1; p >>= 1; )
			t[p] = t[p << 1] + t[p << 1|1];
	}
	int query(int l, int r) {
		int res = 0;
		for (l += N, r = min(r, N) + N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res += t[l++];
			if (r & 1) res += t[--r];
		}
		return res;
	}
} one;

struct {
	ll t[N << 1];
	ll query(int p) {
		ll res = 0;
		for (p += N; p > 0; p >>= 1)
			res += t[p];
		return res;
	}
	
	void update(int l, int r, int del) {
		r = min(r, N);
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) t[l++] += del;
			if (r & 1) t[--r] += del;
		}
	}
} two;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	ll sum = 0, ans = 0;
	rep(k, 0, n) {		
		ans += sum;
		ans += 1ll * k * a[k] - two.query(a[k]);
		for (ll l = 0; l < N; l += a[k]) {
			ans -= one.query(l, l + a[k]) * l;
			two.update(l, l + a[k], l);
		}
		
		sum += a[k];
		one.activate(a[k]);

		cout << ans << ' ';
	}

	cout << '\n';
}