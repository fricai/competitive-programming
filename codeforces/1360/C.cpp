#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 6;
int a[N], odd[N], even[N], co, ce;

bool solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	co = ce = 0;
	rep(i, 0, n) {
		if (a[i] & 1) odd[co++] = a[i];
		else even[ce++] = a[i];
	}
	if (co % 2 == 0 && ce % 2 == 0) return true;
	rep(i, 0, co)
		rep(j, 0, ce)
			if (abs(odd[i] - even[j]) == 1)
				return true;
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';	
}