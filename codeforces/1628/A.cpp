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

vector<int> solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> mex(n);
	// mex[i] = mex of a[i, n)
	{
	vector<int> freq(n);
	int ptr = 0;
	per(i, 0, n) {
		if (a[i] < n) ++freq[a[i]];
		while (ptr < n && freq[ptr] != 0) ++ptr;
		mex[i] = ptr;
	}
	}

	vector<int> res;
	vector<int> freq(n);
	for (int i = 0, j = 0; i < n; i = j) {
		int cur = mex[i];
		int ptr = 0;
		while (j < n && (i == j || ptr != cur)) {
			if (a[j] < n) ++freq[a[j]];
			while (ptr < n && freq[ptr] != 0) ++ptr;
			++j;
		}
		rep(k, i, j) if (a[k] < n) freq[a[k]] = 0;
		res.push_back(cur);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		const auto res = solve();
		cout << sz(res) << '\n';
		for (auto x : res)
			cout << x << ' ';
		cout << '\n';
	}
}
