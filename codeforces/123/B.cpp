#include <algorithm>
#include <iostream>
#include <vector>

#define int ll

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void transform(int &x, int &y) {
	int z = x + y;
	y = y - x;
	x = z;
}

int divide(int a, int b) {
	if (a < 0) return -((-a + b - 1) / b);
	return a / b;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, x1, y1, x2, y2; cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	transform(x1, y1); transform(x2, y2);
	x1 = divide(x1, 2 * a); x2 = divide(x2, 2 * a);
	y1 = divide(y1, 2 * b); y2 = divide(y2, 2 * b);
	cout << max(abs(x1 - x2), abs(y1 - y2));
}