#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using mint = atcoder::modint998244353;

const mint two = mint::raw(2), half = 1 / mint::raw(2);

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	auto cmp = a;
	sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));
	for (auto &x : a)
		x = lower_bound(all(cmp), x) - begin(cmp);

	atcoder::fenwick_tree<mint> t(n);

	mint x = two.pow(n), p = half.pow(n);
	mint ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += t.sum(0, a[i] + 1) * p;
		p *= two;
		x *= half;
		t.add(a[i], x);
	}

	cout << ans.val() << '\n';
}
