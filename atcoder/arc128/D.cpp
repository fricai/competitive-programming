#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 998244353;
using mint = atcoder::static_modint<mod>;
const mint zero = 0, one = 1;

mint solve(vector<int> a) {
	if (sz(a) <= 2) return one;

	auto b = a;
	sort(all(b)); b.erase(unique(all(b)), end(b));
	for (auto &x : a) x = lower_bound(all(b), x) - begin(b);

	int n = sz(a);

	vector<int> cnt(sz(b));
	int non_zero = 0;
	auto add = [&](int x) {
		if (cnt[x]++ == 0)
			++non_zero;
	};
	auto remove = [&](int x) {
		if (--cnt[x] == 0)
			--non_zero;
	};

	vector<int> left(n);
	add(a[n - 1]); add(a[n - 2]);
	for (int i = n - 2, j = i; i >= 1; --i) {
		while (j >= 1 && non_zero <= 2)
			add(a[--j]);
		if (non_zero > 2) left[i] = min(i - 1, j + 1);
		remove(a[i + 1]);
	}

	vector<mint> f(n + 1, one), g(n);
	g[0] = 0;
	g[1] = f[0];
	g[2] = f[0] + f[1];
	rep(i, 1, n - 1) {
		f[i + 1] = f[i] + f[i - 1] + g[left[i]];
		g[i + 1] = g[i] + f[i];
	}
	return f[n - 1];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	mint ans = one;
	vector<int> v;
	rep(i, 0, n) {
		if (!v.empty() && v.back() == a[i]) {
			ans *= solve(v);
			v.clear();
		}
		v.push_back(a[i]);
	}
	ans *= solve(v);
	cout << ans.val() << '\n';
}
