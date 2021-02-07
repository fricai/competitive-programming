#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;

int n;
int ask(int i) {
	++i;
	if (i > n || i < 1) return inf;
	cout << "? " << i << endl;
	int x; cin >> x;
	return x;
}

int f(int l, int r) {
	if (r - l == 1) return l;
	int m = l + (r - l) / 2;
	int L = ask(m - 1), M = ask(m), R = ask(m + 1);
	if (L > M && M < R) return m;
	return L < M ? f(l, m) : f(m + 1, r);
}

signed main() {
	cin >> n;
	int res = f(0, n);
	cout << "! " << res + 1 << endl;
}