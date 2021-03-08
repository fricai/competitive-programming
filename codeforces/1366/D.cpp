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

const int X = 1 << 24;
int p[X];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 2, X)
		if (p[i] == 0)
			for (int j = i; j < X; j += i) p[j] = i;

	int n; cin >> n;
	vector<int> b(n, 1), c(n, 1);
	rep(i, 0, n) {
		int x; cin >> x;
		b[i] = p[x]; c[i] = x;
		while (c[i] % b[i] == 0) c[i] /= b[i];
		if (c[i] == 1) b[i] = c[i] = -1;
	}

	for (auto x : b) cout << x << ' ';
	cout << '\n';
	for (auto x : c) cout << x << ' ';
	cout << '\n';
}