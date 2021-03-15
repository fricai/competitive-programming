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

bool ask(int a, int b) {
	if (a < 0 || b < 0) return 0;
	cout << 1 << " " << a << " " << b << endl;
	string s; cin >> s;
	return s == "TAK";
}

int solve(int l, int r) {
	if (l > r) return -1;
	while (l < r) {
		int m = l + (r - l) / 2;
		if (ask(m, m + 1)) r = m;
		else l = m + 1;
	}
	return l;
}

signed main() {
	int n, k; cin >> n >> k;
	int a = solve(1, n);
	int b = solve(1, a - 1);
	if (!ask(b, a)) b = solve(a + 1, n);
	cout << 2 << ' ' << a << ' ' << b << endl;
}