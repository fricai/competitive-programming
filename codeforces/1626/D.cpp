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

constexpr int B = 20;

int lg(int x) { return 31 - __builtin_clz(x) + ((x & (x - 1)) != 0); }
int f(int x) { return x == 0 ? 1 : 1 << lg(x); }

ll solve() {
	int n; cin >> n;

	vector<int> p(n + 1);
	rep(i, 0, n) {
		int x; cin >> x;
		++p[x];
	}
	partial_sum(begin(p), end(p), begin(p));

	auto val = [&](int x, int y) {
		return f(x) + f(y) + f(n - x - y) - n;
	};
	array<stack<int>, B> st;
	for (int i = 0; i <= n; ++i)
		if (p[i]) st[lg(p[i])].push(p[i]);

	int ans = val(0, n);
	for (int i = n; i >= 0; --i) {
		int c = n - p[i];
		rep(j, 0, B) if (!st[j].empty()) uin(ans, val(c, st[j].top()));
		if (p[i]) st[lg(p[i])].pop();
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
