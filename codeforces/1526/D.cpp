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


map<char, int> m = {{'A', 0}, {'N', 1}, {'O', 2}, {'T', 3}};
string inv_m = "ANOT";

const int A = 4;
int cnt[A];
ll inv[A][A];

string solve() {
	string s; cin >> s;
	rep(i, 0, A) {
		cnt[i] = 0;
		rep(j, 0, A) inv[i][j] = 0;
	}
	
	rep(c, 0, A) {
		for (auto t : s) {
			inv[m[t]][c] += cnt[c];
			cnt[c] += m[t] == c;
		}
	}
	
	ll till_now = -1;
	vector<int> res, ord(A);
	iota(all(ord), 0);
	do {
		ll inv_count = 0;
		rep(i, 0, A)
			rep(j, i + 1, A)
				inv_count += inv[ord[i]][ord[j]];
		if (uax(till_now, inv_count))
			res = ord;
	} while (next_permutation(all(ord)));

	string ans = "";

	for (auto x : res)
		rep(j, 0, cnt[x])
			ans += inv_m[x];
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}