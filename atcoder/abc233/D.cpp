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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	map<ll, int> z;
	z[0] = 1;

	ll sum = 0, ans = 0;
	for (auto x : a) {
		sum += x;
		ans += z[sum - k];
		++z[sum];
	}
	cout << ans << '\n';
}
