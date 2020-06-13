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
	for (int i = 2, cntr = 0; i <= n; ++i) {
		if (a[i] == 0) {
			a[i] = ++cntr;
			for (int64_t j = 1ll * i * i; j <= n; j += i)
				a[j] = cntr;
		}
	}

	for (int i = 2; i <= n; ++i) cout << a[i] << ' ';
}