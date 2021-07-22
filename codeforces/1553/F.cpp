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

template<class S, class T>
pair<S, T> operator+(const pair<S, T> &a, const pair<S, T> &b) {
	return {a.first + b.first, a.second + b.second};
}

struct {
	using node = pair<ll, ll>;
	node t[N << 1];
	void activate(int p) {
		t[p + N] = {p, 1};
		for (p += N; p >>= 1; )
			t[p] = t[p << 1] + t[p << 1|1];
	}
	node query(int l, int r) {
		r = min(r, N);
		node res = {0, 0};
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = res + t[l++];
			if (r & 1) res = res + t[--r];
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

	vector<ll> ans(n);
	
	rep(k, 0, n) {
		if (k) ans[k] = ans[k - 1];

		ans[k] += 1ll * k * a[k] - two.query(a[k]);
		for (int l = 0; l < N; l += a[k]) {
			auto [sum, cnt] = one.query(l, l + a[k]);
			ans[k] += sum - cnt * l;
			two.update(l, l + a[k], l);
		}
		one.activate(a[k]);
	}
	
	for (auto x : ans)
		cout << x << ' ';
	cout << '\n';
}