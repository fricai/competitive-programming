#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int len(int x) {
	if (x == 0) return 0;
	return 1 + len(x / 10);
}

int solve() {
	int x1, p1, x2, p2; cin >> x1 >> p1 >> x2 >> p2;
	if (len(x1) + p1 > len(x2) + p2)
		return +1;
	if (len(x1) + p1 < len(x2) + p2)
		return -1;
	while (len(x1) < len(x2)) x1 *= 10, --p1;
	while (len(x2) < len(x1)) x2 *= 10, --p2;
	assert(len(x1) + p1 == len(x2) + p2);
	if (x1 == x2)
		return 0;
	if (x1 < x2)
		return -1;
	return +1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char x[3] = {'<', '=', '>'};

	int t; cin >> t;
	while (t--) cout << x[solve() + 1] << '\n';
}
