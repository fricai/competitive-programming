#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

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


template<class I> int lis(const vector<I>& S) {
	if (S.empty()) return {};
	vector<int> prev(sz(S));
	using p = pair<I, int>;
	vector<p> res;
	rep(i, 0, sz(S)) {
		// change 0 -> i for longest non-decreasing subsequence
		auto it = lower_bound(all(res), p{S[i], 0});
		if (it == res.end()) res.emplace_back(), it = res.end() - 1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it - 1)->second;
	}
	return sz(res);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> p(n), q(n);
	for (auto &x : p) cin >> x;
	for (auto &x : q) cin >> x;

	vector<int> inv_q(n + 1);
	rep(i, 0, n) inv_q[q[i]] = i;

	vector<vector<int>> mul(n + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			mul[i].push_back(inv_q[j]);
 
	for (auto &v : mul) sort(rall(v));

	vector<int> c;
	for (auto a : p)
		for (auto j : mul[a])
			c.push_back(j);

	cout << lis(c) << '\n';
}

