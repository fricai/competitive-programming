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

bool check(vector<int> a, int x) {
	vector<int> b;
	for (auto y : a)
		if (x != y)
			b.push_back(y);
	for (int l = 0, r = sz(b) - 1; l < r; ++l, --r) {
		if (b[l] != b[r]) {
			return false;
		}
	}
	return true;
}

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	for (int l = 0, r = n - 1; l < r; ++l, --r) {
		if (a[l] != a[r]) {
			return check(a, a[l]) || check(a, a[r]);
		}
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}
