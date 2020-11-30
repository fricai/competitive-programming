#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 9;
string f[N];

string solve() {
	int n, k; cin >> n >> k;
	auto up = [&](char c) -> char { return (c - 'a' + 1) % k + 'a'; };
	auto down = [&](char c) -> char { return (c - 'a' + k - 1) % k + 'a'; };

	string s; cin >> s;
	rep(i, 0, n) {
		f[i + 1] = f[i] + s[i];
		ckmin(f[i + 1], f[i] + up(s[i]));
		ckmin(f[i + 1], f[i] + down(s[i]));

		if (i > 0)  {
			ckmin(f[i + 1], f[i].substr(0, i - 1) + s[i] + f[i].back());
			ckmin(f[i + 1], f[i - 1] + s[i] + s[i - 1]);
			ckmin(f[i + 1], f[i - 1] + up(s[i]) + s[i - 1]);
			ckmin(f[i + 1], f[i - 1] + down(s[i]) + s[i - 1]);
			ckmin(f[i + 1], f[i - 1] + s[i - 1] + s[i]);
		}
		if (i > 1) ckmin(f[i + 1], f[i - 1].substr(0, i - 2) + s[i] + f[i - 1].back() + s[i - 1]);
	}
	return f[n];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}