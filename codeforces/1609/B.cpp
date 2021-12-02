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

	int n, q; cin >> n >> q;
	string s; cin >> s;

	vector<bool> one(n);
	int cur = 0;
	auto update = [&](int i) {
		if (i < 0 || i + 2 >= n)
			return;
		cur -= one[i];
		one[i] = s.substr(i, 3) == "abc";
		cur += one[i];
	};
	rep(i, 0, n) update(i);

	while (q--) {
		int i; cin >> i; --i; cin >> s[i];
		for (int j = -2; j <= +2; ++j)
			update(i + j);
		cout << cur << '\n';
	}
}
