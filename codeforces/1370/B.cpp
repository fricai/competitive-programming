#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 11;
int a[N], b[N], v[N], c[N];

void solve() {
	int n; cin >> n;
	int odd = 0, even = 0;
	rep(i, 0, 2 * n) {
		int x; cin >> x; v[i + 1] = x;
		if (x & 1) a[odd++] = i + 1;
		else b[even++] = i + 1;
	}

	if (odd & 1) --odd, --even;
	else {
		if (odd == 0) even -= 2;
		else odd -= 2;
	}
	int x = 0;
	assert(x % 2 == 0);
	rep(i, 0, odd) c[x++] = a[i];
	rep(i, 0, even) c[x++] = b[i];
	for (int i = 0; i + 1 < x; i += 2)
		cout << c[i] << ' ' << c[i + 1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}