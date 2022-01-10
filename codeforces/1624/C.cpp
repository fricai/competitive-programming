#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

bool solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(rall(a));

	for (int i = n; i > 0; --i) {
		bool found = false;
		for (auto &x : a) {
			int y = x;
			while (y > 0 && y != i) y /= 2;
			if (y != 0) {
				assert(y == i);
				x = 0;
				found = true;
				break;
			}
		}
		if (!found) return false;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}
