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
	assert(k == 2);
	int cur = 0;
	for (int i = 0; i < n; ++i)
		if (ask(cur ^ i)) return;
		else cur = i;
	assert(0);
}

signed main() {
	int t; cin >> t;
	while (t--) solve();
}