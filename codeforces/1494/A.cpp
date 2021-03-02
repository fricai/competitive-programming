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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool solve() {
	string s; cin >> s;
	for (auto a : {-1, +1}) {
		for (auto b : {-1, +1}) {
			for (auto c : {-1, +1}) {
				bool works = true;
				int open = 0;
				rep(i, 0, sz(s)) {
					if (s[i] == 'A') open += a;
					if (s[i] == 'B') open += b;
					if (s[i] == 'C') open += c;
					if (open < 0) works = false;
				}
				if (open) works = false;
				if (works) return true;
			}
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}