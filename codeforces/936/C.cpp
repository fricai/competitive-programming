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

const int N = 1 << 11, A = 26;
vector<int> z, op;
int n;

void do_op(int k) {
	if (k == 0) return;
	assert(k > 0);
	op.push_back(k);
	vector<int> res;
	per(i, n - k, n) res.push_back(z[i]);
	rep(i, 0, n - k) res.push_back(z[i]);
	z = move(res);
}

vector<int> f[A];

int get(int x) {
	rep(i, 0, n) if (z[i] == x) return i;
	assert(false);
	return -1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	string s, t; cin >> s >> t;
	string _s = s, _t = t;
	
	sort(all(_s)); sort(all(_t));
	if (_s != _t) return cout << "-1\n", 0;

	rep(i, 0, n) f[t[i] - 'a'].push_back(i);
	rep(i, 0, n) {
		int c = s[i] - 'a';
		z.push_back(f[c].back());
		f[c].pop_back();
	}

	bool parity = 0;
	do_op(n - get(0) - 1);
	for (int l = 1, r = n - 1, k = 1; l < r; ++l, --r, k += 2, parity ^= 1) {
		int u = l, v = r;
		if (parity) swap(u, v);
		do_op(n - get(u) - 1);
		do_op(n);
		do_op(k);
		do_op(n - get(v));
		do_op(n - get(u) - 1);
	}

	if (!parity) do_op(n);
	do_op(n - get(0));
	do_op(n - get(0) - 1);
	do_op(n);

	cout << sz(op) << '\n';
	for (auto x : op) cout << x << ' ';
	cout << '\n';
}