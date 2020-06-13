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

const int N = 1 << 17;
int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	bool odd = false, even = false;
	rep(i, 0, n) {
		cin >> a[i];
		if (a[i] & 1) odd = true;
		else even = true;
	}
	if (!odd || !even) {
		rep(i, 0, n) cout << a[i] << ' ';
		return 0;
	}
	sort(a, a + n);
	rep(i, 0, n) cout << a[i] << ' ';
}