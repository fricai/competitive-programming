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

const int N = 1 << 17, X = 1 << 19;
int t[X << 1], lz[X << 1];
vector<int> add[X], sub[X];

int lo, hi, x;
void push(int v) {
	t[v] += lz[v];
	if (v < X) {
		lz[v << 1|0] += lz[v];
		lz[v << 1|1] += lz[v];
	}
	lz[v] = 0;
}
void rec(int v, int l, int r) {
	push(v);
	if (hi <= l || r <= lo) return;
	if (lo <= l && r <= hi) return lz[v] += x, push(v);
	int m = (l + r) / 2;
	rec(v << 1, l, m); rec(v << 1|1, m, r);
	t[v] = max(t[v << 1], t[v << 1|1]);
}
void inc(int l, int r, int val) {
	lo = l; hi = r + 1; x = val;
	rec(1, 0, X);
}

int query(int v, int l, int r) {
	push(v);
	if (r - l == 1) return l;
	int m = (l + r) / 2;
	return t[v << 1] > t[v << 1|1] ? query(v << 1, l, m) : query(v << 1|1, m, r);
}

int L[N], R[N], V[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	rep(i, 0, n) {
		cin >> L[i] >> V[i] >> R[i];
		add[V[i]].push_back(i);
		sub[R[i]].push_back(i);
	}

	int mx = 0, a, b;
	rep(y, 0, X) {
		for (auto i : add[y]) inc(L[i], V[i], +1);
		if (ckmax(mx, t[1])) {
			a = query(1, 0, X), b = y;
		}
		for (auto i : sub[y]) inc(L[i], V[i], -1);
	}
	
	cout << mx << '\n';
	rep(i, 0, n)
		if (L[i] <= a && a <= V[i] && V[i] <= b && b <= R[i])
			cout << i + 1 << ' ';
}