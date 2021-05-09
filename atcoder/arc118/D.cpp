#include <bits/stdc++.h>
#include <atcoder/modint>

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

int p;
using mint = atcoder::modint;
mint a, b;

bool check(mint x, mint y) {
	return a * x == y || x == a * y || b * x == y || x == b * y;
}

void answer(vector<mint> v) {
	vector<bool> vis(p, 0);
	for (auto x : v) vis[x.val()] = 1;
	rep(i, 1, p) if (!vis[i]) return;

	v.push_back(1);
	assert(sz(v) == p);
	rep(i, 1, p)
		if (!check(v[i - 1], v[i]))
			return;
	
	cout << "Yes\n";
	for (auto x : v) cout << x.val() << ' ';
	cout << '\n';
	exit(0);
}

template<class T>
vector<T> cross(vector<T> a, vector<T> b) {
	vector<T> res;
	rep(i, 0, sz(a)) {
		if (i & 1) {
			per(j, 0, sz(b))
				res.push_back(a[i] * b[j]);
		} else {
			rep(j, 0, sz(b))
				res.push_back(a[i] * b[j]);
		}
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int _a, _b;
	cin >> p >> _a >> _b;
	mint::set_mod(p);
	a = _a;
	b = _b;

	vector<mint> A = {1}, B = {1};
	for (mint x = a; x != 1; x *= a)
		A.push_back(x);
	for (mint x = b; x != 1; x *= b)
		B.push_back(x);

	assert((p - 1) % sz(A) == 0);
	int d = (p - 1) / sz(A);
	if (d <= sz(B)) answer(cross(A, {begin(B), begin(B) + d}));

	assert((p - 1) % sz(B) == 0);
	d = (p - 1) / sz(B);
	if (d <= sz(A)) answer(cross(B, {begin(A), begin(A) + d}));
	
	cout << "No\n";
}