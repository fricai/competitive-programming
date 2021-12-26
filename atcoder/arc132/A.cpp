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

	int n; cin >> n;
	vector<int> r(n), c(n);
	for (auto &x : r) cin >> x;
	for (auto &x : c) cin >> x;

	vector<int> ord(n + 1);
	for (int i = n, j = 1, k = 1; k <= n; ++k) {
		if (k & 1) ord[i--] = k;
		else ord[j++] = k;
	}

	char x[2] = {'.', '#'};

	int q; cin >> q;
	while (q--) {
		int i, j; cin >> i >> j; --i; --j;
		i = r[i];
		j = c[j];
		if (ord[i] > ord[j]) swap(i, j);
		cout << x[min(ord[i], ord[j]) & 1];
	}
	cout << '\n';
}
