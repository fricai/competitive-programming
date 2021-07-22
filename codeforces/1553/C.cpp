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

int solve() {
	string s; cin >> s;
	vector<int> v;
	rep(i, 0, 10) if (s[i] == '?') v.push_back(i);

	int ans = 10;
	rep(S, 0, 1 << sz(v)) {
		auto t = s;
		rep(i, 0, sz(v))
			if (S >> i & 1)
				s[v[i]] = '1';
			else
				s[v[i]] = '0';
		int a[2] = {0, 0};
		rep(i, 0, 10) {
			bool b = i & 1;
			if (s[i] == '1') ++a[b];
			
			int c[2] = {a[0], a[1]};
			rep(j, i + 1, 10)
				++c[j & 1];
			
			if (a[b] > c[!b] || a[!b] > c[b]) {
				uin(ans, i + 1);
				break;
			}
		}
	}
	
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}