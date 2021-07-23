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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	int f[2] = {0, 0};
	for (auto &x : a) {
		cin >> x;
		++f[x - 1];
	}
	
	if (f[0] && f[1]) {
		cout << "2 1 ";
		--f[0]; --f[1];
		assert(f[0] >= 0 && f[1] >= 0);
		while (f[1] != 0) cout << "2 ", --f[1];
		while (f[0] != 0) cout << "1 ", --f[0];	
	} else {
		int b = f[0] ? 1 : 2;
		rep(i, 0, n) cout << b << ' ';
	}
	cout << '\n';
}