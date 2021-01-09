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

const int N = 1 << 20;
struct node {
	int mx = 0, mn = 0;
	void operator+=(int x) {
		mx += x;
		mn += x;
	}
} t[N << 1];
int lz[N << 1];
int n;

node merge(node a, node b) { return {max(a.mx, b.mx), min(a.mn, b.mn)}; }

void push(int v) {
	t[v] += lz[v];
	if (v < N) {
		lz[v << 1|0] += lz[v];
		lz[v << 1|1] += lz[v];
	}
	lz[v] = 0;
}

int lo, hi, x;
// node query(int v, int l, int r) {
// 	push(v);
// 	if (hi <= l || r <= lo) return {0, 0};
// 	if (l <= lo && hi <= r) return t[v];
// 	int m = (l + r) / 2;
// 	return merge(query(v << 1, l, m), query(v << 1|1, m, r));
// }
// node query(int l, int r) { return lo = l, hi = r, query(1, 0, n); }

void upd(int v, int l, int r) {
	// cerr << v << ' ' << l << ' ' << r << ' ' << lo << ' ' << hi << '\n';
	push(v);
	if (hi <= l || r <= lo) return;
	if (lo <= l && r <= hi) return lz[v] += x, push(v);
	int m = (l + r) / 2;
	upd(v << 1|0, l, m);
	upd(v << 1|1, m, r);
	t[v] = merge(t[v << 1], t[v << 1|1]);
}

void update(int l, int r, int v) {
	lo = l; hi = r; x = v;
	upd(1, 0, n);
}

int val[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int sum = 0, pos = 0;
	rep(i, 0, n) {
		char c; cin >> c;
		if (c == 'L') pos = max(0, pos - 1);
		else if (c == 'R') ++pos;
		else {
			update(pos, n, -val[pos]);
			sum -= val[pos];
			if (c == '(') val[pos] = +1;
			else if (c == ')') val[pos] = -1;
			else val[pos] = 0;
			update(pos, n, +val[pos]);
			sum += val[pos];
		}
		if (sum == 0 && t[1].mn == 0) cout << t[1].mx << ' ';
		else cout << "-1 ";
	}
}