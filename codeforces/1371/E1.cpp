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

const int A = 1 << 11;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p; cin >> n >> p;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(all(a));

	vector<int> op;
	rep(x, 1, A) {
		int res = 1;
		for (int i = 0, k = 0, y = x; i < n; ++y, ++i) {
			while (k < n && a[k] <= y) ++k;
			res *= k - i;
			res %= p;
		}
		if (res) op.push_back(x);
	}

	cout << sz(op) << '\n';
	for (auto x : op) cout << x << ' ';
}