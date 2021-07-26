#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	if (find(all(a), k) == end(a))
		return false;
	int cnt = 0;
	rep(i, 0, n)
		cnt += a[i] == k;
	if (cnt == n)
		return true;
	rep(i, 0, n) {
		if (a[i] < k) continue;
		rep(j, max(0, i - 2), i)
			if (a[j] >= k)
				return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "yes" : "no") << '\n';
}