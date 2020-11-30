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
string f[N], g[N];

string solve() {
	int n, k; cin >> n >> k;
	auto up = [&](char c) -> char { return (c - 'a' + 1) % k + 'a'; };
	auto down = [&](char c) -> char { return (c - 'a' + k - 1) % k + 'a'; };

	string s; cin >> s;
	rep(i, 0, n) {
		f[i + 1] = g[i + 1] = f[i] + s[i];
		ckmin(f[i + 1], f[i] + up(s[i]));
		ckmin(f[i + 1], f[i] + down(s[i]));

		if (i > 0)  {
			ckmin(f[i + 1], f[i].substr(0, i - 1) + s[i] + f[i].back());

			auto t = g[i]; char c = t.back(); t.pop_back();
			ckmin(f[i + 1], t + s[i] + c);
			ckmin(f[i + 1], t + up(s[i]) + c);
			ckmin(f[i + 1], t + down(s[i]) + c);
		}
		if (i > 1) ckmin(f[i + 1], g[i].substr(0, i - 2) + s[i] + g[i].substr(i - 2));
		ckmin(f[i + 1], g[i] + s[i]);
	}
	return f[n];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}