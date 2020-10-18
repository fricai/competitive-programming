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

// C++ program to find lexicographically 
// maximum value after k swaps. 
#include <bits/stdc++.h> 
using namespace std; 

const string t = "atcoder";

bool ok(string s, int k) {
	for (int i = 0; i < sz(s) && k > 0; ++i) {
		int idx = i;
		rep(j, i + 1, sz(s)) {
			if (k < j - i) break;
			if (s[j] > s[idx]) idx = j;
		}
		for (int j = idx; j > i; --j) swap(s[j], s[j - 1]);
		k -= idx - i;
	}
	return s > t;
}

int solve() {
	string s; cin >> s;
	if (t < s) return 0;
	string z = s;
	sort(all(z));
	reverse(all(z));
	if (z <= t) return -1;
	int l = 0, r = sz(s) * sz(s);
	while (r - l > 1) {
		int m = (l + r) / 2;
		(ok(s, m) ? r : l) = m;
	}
	return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}