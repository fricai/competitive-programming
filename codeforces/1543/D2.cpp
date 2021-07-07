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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int Y = 2e7;

bool ask(int y) {
	assert(0 <= y && y <= Y);
	cout << y << endl;
	int r; cin >> r;
	assert(0 <= r && r <= 1);
	return r;
}

void solve() {
	int n, k; cin >> n >> k;

	assert(k <= 100);

	auto get_rep = [&](int x) {
		vector<int> v;
		while (x) {
			v.push_back(x % k);
			x /= k;
		}
		return v;
	};

	auto get_num = [&](vector<int> v) {
		int x = 0;
		while (!v.empty()) {
			x = k * x + v.back();
			v.pop_back();
		}
		return x;
	};

	auto add = [&](int x, int y) { return x += y, x < k ? x : x - k; };
	auto sub = [&](int x, int y) { return x -= y, x < 0 ? x + k : x; };

	auto kadd = [&](int x, int y) { // x +_k y
		auto X = get_rep(x);
		auto Y = get_rep(y);
		if (sz(X) < sz(Y)) X.resize(sz(Y), 0);
		rep(i, 0, sz(Y))
			X[i] = add(X[i], Y[i]);
		return get_num(X);
	};

	auto ksub = [&](int x, int y) { // x -_k y
		auto X = get_rep(x);
		auto Y = get_rep(y);
		if (sz(X) < sz(Y)) X.resize(sz(Y), 0);
		rep(i, 0, sz(Y))
			X[i] = sub(X[i], Y[i]);
		return get_num(X);
	};

	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			// cur -_k x is the number rn
			int to_ask = ksub(cur, i);
			if (ask(to_ask)) return;
			/*
				(cur - x) + z = to_ask
				z = (to_ask - cur) + x
			*/
			cur = ksub(to_ask, cur);
		} else {
			// cur +_k x is the number rn
			int to_ask = kadd(cur, i);
			if (ask(to_ask)) return;
			/*
				(cur + x) + z = to_ask
				z = to_ask - (cur + x)
				  = (to_ask - cur) - x
			*/

			cur = ksub(to_ask, cur);
		}
	}
}

signed main() {
	int t; cin >> t;
	while (t--) solve();
}