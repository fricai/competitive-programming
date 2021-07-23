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

const int K = 19, N = 1 << K, inf = N << 4;
int n, k;

int mx[N << 1], mn[N << 1], del[N << 1], L[N], R[N];

void build(vector<int> a) {
	fill_n(mx, n + n, -inf);
	fill_n(mn, n + n, +inf);
	fill_n(del, n + n, +inf);
	
	for (auto x : a)
		mx[x + n] = mn[x + n] = 0;
	
	auto rec = [&](auto &&self, int v, int l, int r) {
		if (r - l == 1)
			return;
		int m = (l + r) / 2;
		
		L[v] = v << 1|0;
		R[v] = v << 1|1;
		self(self, L[v], l, m);
		self(self, R[v], m, r);
		
		mx[v] = max(l + mx[L[v]], m + mx[R[v]]) - l;
		mn[v] = min(l + mn[L[v]], m + mn[R[v]]) - l;
		del[v] = min({
			del[L[v]],
			mn[R[v]] + m - mx[L[v]] - l,
			del[R[v]]
		});
	};
	rec(rec, 1, 0, n);
}

void flip(int b) {
	auto rec = [&](auto &&self, int v, int l, int r, int h) {
		if (r - l == 1) {
			assert(false);
			return;
		}
		
		int m = (l + r) / 2;
		if (h > b) {
			self(self, L[v], l, m, h - 1);
			self(self, R[v], m, r, h - 1);
		} else
			swap(L[v], R[v]);
		
		mx[v] = max(l + mx[L[v]], m + mx[R[v]]) - l;
		mn[v] = min(l + mn[L[v]], m + mn[R[v]]) - l;
		del[v] = min({
			del[L[v]],
			mn[R[v]] + m - mx[L[v]] - l,
			del[R[v]]
		});
	};
	rec(rec, 1, 0, n, k - 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m; cin >> m >> k;
	n = 1 << k;
	vector<int> a(m);
	for (auto &x : a) cin >> x;
	build(a);

	vector<int> ans(n);

	int cur = 0;
	ans[cur] = del[1];
	auto g = [](int n) { return n ^ (n >> 1); };
	rep(x, 1, n) {
		int j = k - 32 + __builtin_clz(g(x) ^ g(x - 1));
		cur ^= 1 << j;
		flip(j);
		ans[cur] = del[1];
	}

	for (auto x : ans)
		cout << x << ' ';
	cout << '\n';
}