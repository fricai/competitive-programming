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

ll C(ll x) { return x * (x - 1) / 2; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> cnt(7);

	ll cur = 0;
	rep(i, 0, 7) {
		while (cur + C(cnt[i]) <= n)
			++cnt[i];
		--cnt[i];
		cur += C(cnt[i]);
	}

	vector<int> r;
	rep(i, 0, 7)
		rep(j, 0, cnt[i])
			r.push_back(i);

	vector<int> s;
	for (int i = 1, p = 1; i < sz(r); ++i, p = 5 * p % 7) {
		int k = (r[i] - r[i - 1] + 7) * p % 7;
		s.push_back(k);
	}

	reverse(all(s));
	for (auto &x : s)
		cout << (x == 0 ? 7 : x);
	cout << '\n';
}
