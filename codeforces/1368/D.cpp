#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <set>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int B = 25;
const int N = 1 << 18;
ll a[N];

void f(int i, int j) { // i > j
	// assert(i > j);
	ll x = a[i] | a[j], y = a[i] & a[j];
	a[i] = x; a[j] = y;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	sort(a, a + n);

	rep(b, 0, B) {
		vector<int> on, off;
		rep(i, 0, n)
			if (a[i] & 1 << b) on.eb(i);
			else off.eb(i);		
		trav(i, on) {
			if (off.empty() || off.back() < i) break;
			f(off.back(), i);
			off.pop_back();
		}
	}

	ll ans = 0;
	rep(i, 0, n) ans += a[i] * a[i];
	cout << ans;
}