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

const int M = 998244353, N = 1 << 18;

int mul(ll x, int y) { return x * y % M; }
int add(int x, int y) {
	x += y;
	if (M <= x) x -= M;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) x += M;
	return x;
}

int inv(int a) {
	int res = 1;
	for (int e = M - 2; e; e >>= 1, a = mul(a, a))
		if (e & 1) res = mul(res, a);
	return res;
}


int sum[N], prod[N];
int f(int l, int r) { return mul(sub(sum[r], sum[l]), inv(prod[r])); }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	vector<int> p(n);
	int inv_100 = inv(100);
	for (auto &x : p) cin >> x, x = mul(x, inv_100);
	
	prod[0] = 1;
	rep(i, 0, n) prod[i + 1] = mul(p[i], prod[i]);
	sum[0] = 1;
	rep(i, 0, n) sum[i + 1] = add(sum[i], prod[i]);
	
	set<int> checkpoints = {0, n};
	
	int cur = f(0, n);
	while (q--) {
		int u; cin >> u; --u;
		auto [it, inserted] = checkpoints.insert(u);
		auto L = *prev(it), R = *next(it);
		if (inserted) {
			cur = sub(cur, f(L, R));
			cur = add(cur, f(L, u));
			cur = add(cur, f(u, R));
		} else {
			checkpoints.erase(it);
			cur = add(cur, f(L, R));
			cur = sub(cur, f(L, u));
			cur = sub(cur, f(u, R));
		}
		cout << cur << '\n';
	}
}