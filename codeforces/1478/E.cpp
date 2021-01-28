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

const int N = 1 << 18;
ll t[N << 1];
bool val[N << 1], lazy[N << 1];

void push(int v, int l, int r) {
	if (lazy[v]) {
		t[v] = (r - l) * val[v];
		if (v < N) {
			lazy[v << 1|0] = lazy[v << 1|1] = 1;
			val[v << 1|0] = val[v << 1|1] = val[v];
		}
		lazy[v] = 0;
	}
}

int lo, hi, x;
int n;

void upd(int v, int l, int r) {
	push(v, l, r);
	if (hi <= l || r <= lo) return;
	if (lo <= l && r <= hi) return lazy[v] = 1, val[v] = x, push(v, l, r);
	int m = (l + r) / 2;
	upd(v << 1, l, m); upd(v << 1|1, m, r);
	t[v] = t[v << 1] + t[v << 1|1];
}

void update(int l, int r, int v) {
	lo = l; hi = r; x = v;
	upd(1, 0, n);
}

string s, f;
void build(int v, int l, int r) {
	val[v] = lazy[v] = 0;
	if (r - l == 1) return void(t[v] = f[l] - '0');
	int m = (l + r) / 2;
	build(v << 1|0, l, m);
	build(v << 1|1, m, r);
	t[v] = t[v << 1] + t[v << 1|1];
}

int sum(int v, int l, int r) {
	push(v, l, r);
	if (hi <= l || r <= lo) return 0;
	if (lo <= l && r <= hi) return t[v];
	int m = (l + r) / 2;
	return sum(v << 1, l, m) + sum(v << 1|1, m, r);
}

int sum(int l, int r) { return lo = l, hi = r, sum(1, 0, n); }

bool solve() {
	int q; cin >> n >> q >> s >> f;
	vector<int> L(q), R(q);
	per(i, 0, q) cin >> L[i] >> R[i], --L[i];
	build(1, 0, n);
	
	// rep(i, 0, n) cerr << sum(i, i + 1);
	// cerr << '\n';

	rep(i, 0, q) {
		int ones = sum(L[i], R[i]);
		int zero = R[i] - L[i] - ones;

		// cerr << '\n';
		// cerr << ones << ' ' << zero << ' ';
		if (ones == zero) return false;
		if (ones > zero) update(L[i], R[i], 1);
		else update(L[i], R[i], 0);
		// rep(i, 0, n) cerr << sum(i, i + 1);
		// cerr << '\n';
	}

	rep(i, 0, n) if (sum(i, i + 1) != s[i] - '0') return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}