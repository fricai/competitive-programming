#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <atcoder/segtree>

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

int op(int a, int b) { return max(a, b); }
int e() { return 0; }
using st = atcoder::segtree<int, op, e>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> p(n), q(n);
	for (auto &x : p) cin >> x;
	for (auto &x : q) cin >> x;

	st t(n);
	auto f = [&](int x) { return t.prod(0, x + 1); };
	// range update [i, n) <=> change value of i
	// get value at i <=> get max over [0, i]

	vector<int> inv_q(n + 1);
	rep(i, 0, n) inv_q[q[i]] = i;

	vector<vector<int>> mul(n + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			mul[i].push_back(inv_q[j]);

	for (auto &v : mul) sort(rall(v));

	for (auto a : p) {
		for (auto j : mul[a]) {
			const int val = f(j - 1);
			if (f(j) < 1 + val) {
				t.set(j, 1 + val);
			}
		}
	}

	cout << t.all_prod() << '\n';
}
