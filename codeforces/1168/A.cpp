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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n, m;
vector<int> a;
bool check(int x) {
	int p = 0;
	for (auto y : a) {
		if ((y <= p && p <= x + y) || (y <= p + m && p + m <= x + y)) continue;
		if (y < p) return 0;
		else p = y;
	}
	return 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	a.resize(n);
	for (auto &x : a) cin >> x;

	int l = -1, r = m;
	while (r - l > 1) {
		ll m = l + (r - l) / 2;
		(check(m) ? r : l) = m;
	}
	cout << r << '\n';
}