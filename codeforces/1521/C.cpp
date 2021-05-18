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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

int query(int t, int i, int j, int x) {
	assert(i != j);
	assert(1 <= t && t <= 2);

	cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;

	int res = -1; cin >> res;
	assert(res != -1);
	return res;
}

int find_one() {
	for (int i = 0; i + 1 < n; i += 2) {
		int ask = query(2, i, i + 1, 1);
		if (ask > 2) continue;
		if (ask == 1)
			return i;
		if (query(2, i + 1, i, 1) == 1)
			return i + 1;
	}
	assert(n & 1);
	return n - 1;
}

void solve() {
	cin >> n;

	int one = find_one();
	vector<int> p(n);

	p[one] = 1;
	for (int i = 0; i < n; ++i) {
		if (i == one) continue;
		p[i] = query(1, one, i, n - 1);
	}

	cout << "! ";
	for (auto x : p) cout << x << ' ';
	cout << endl;
}

signed main() {

	int t; cin >> t;
	while (t--) solve();
}