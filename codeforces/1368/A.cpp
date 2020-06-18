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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--) {
		int a, b, n; cin >> a >> b >> n;
		int k = 0;
		if (a > b) swap(a, b); // a < b
		while (b <= n) {
			a += b;
			swap(a, b);
			++k;
		}
		cout << k << '\n';
	}
}