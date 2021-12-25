#include <bits/stdc++.h>

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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string x; cin >> x;

	int n = sz(x);
	vector<int> v(n);
	rep(i, 0, n) v[i] = x[i] - '0';

	rep(i, 1, n) v[i] += v[i - 1];
	reverse(all(v));

	for (int i = 0; i < sz(v); ++i) {
		int del = v[i] / 10;
		v[i] %= 10;
		if (del != 0) {
			if (i + 1 == sz(v)) v.push_back(del);
			else v[i + 1] += del;
		}
	}

	reverse(all(v));
	for (auto x : v) cout << x;
	cout << '\n';
}
