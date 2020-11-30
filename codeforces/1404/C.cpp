#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 19;
int mn[N << 1], lz[N << 1], n;

void push(int v) {
	mn[v] += lz[v];
	if (v < N) {
		lz[v << 1|1] += lz[v];
		lz[v << 1|0] += lz[v];
	}
	lz[v] = 0;
}

int lo, hi, x;
void upd(int v, int l, int r) {
	push(v);
	if (hi <= l || r <= lo) return;
	if (lo <= l && r <= hi) return lz[v] = x, push(v);
	int m = (l + r) / 2;
	upd(v << 1, l, m); upd(v << 1|1, m, r);
	mn[v] = min(mn[v << 1], mn[v << 1|1]);
}
void update(int v, int l, int r) { lo = l; hi = r; x = v; upd(1, 0, n); }

int get(int v, int l, int r) {
	push(v);
	if (mn[v] > 0) return n;
	if (r - l == 1) return l;
	int m = (l + r) / 2;
	int res = get(v << 1|1, m, r);
	return res < n ? res : get(v << 1, l, m);	
}

int t[N << 1];
void increment(int p) {
	for (t[p += n]++; p >>= 1; ) t[p] = t[p << 1] + t[p << 1|1];
}
int sum(int l, int r) {
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

int ans[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> n >> q;
	rep(i, 0, n) {
		int x; cin >> x;
		x = i - x + 1;
		update(x < 0 ? N : x, i, i + 1);
	}

	vector<int> seq;
	for (int lst; (lst = get(1, 0, n)) < n; ) {
		seq.push_back(lst);
		update(N, lst, lst + 1);
		update(-1, lst + 1, n);
	}

	vector<tuple<int, int, int>> E;
	rep(i, 0, q) {
		int x, y; cin >> x >> y;
		E.emplace_back(x, n - y, i);
	}
	sort(rall(E));

	int i = 0;
	for (auto &[l, r, idx] : E) {
		while (i < sz(seq) && l <= seq[i]) {
			increment(seq[i]);
			++i;
		}
		ans[idx] = sum(0, r);
	}
	rep(i, 0, q) cout << ans[i] << '\n';
}