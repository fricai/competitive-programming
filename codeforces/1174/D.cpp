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

const int N = 1 << 18;
int a[N];
bool busy[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int b, x; cin >> b >> x;
	int n = 1 << b;
	int cntr = 0;
	if (n <= x) rep(i, 0, n) a[cntr++] = i;
	else {
		rep(i, 0, n) {
			if (!busy[i]) {
				a[cntr++] = i;
				busy[i] = true;
				busy[i ^ x] = true;
			}
		}
	}

	cout << cntr - 1 << '\n';
	rep(i, 1, cntr) cout << (a[i] ^ a[i - 1]) << ' ';
}