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

const int N = 1 << 17;
string s[N];
bool can[10];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;	
	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n) {
		if (!i || sz(s[i]) > sz(s[i - 1])) {
			if (s[i][0] == '?') s[i][0] = '1';
			rep(j, 1, sz(s[i])) if (s[i][j] == '?') s[i][j] = '0';
		} else if (sz(s[i - 1]) > sz(s[i])) return cout << "NO", 0;
		else {
			bool flip_point = 0;
			int pos = sz(s[i]);
			rep(j, 0, sz(s[i])) {
				if (s[i][j] != '?' && s[i][j] != s[i - 1][j]) {
					if (s[i][j] > s[i - 1][j]) flip_point = true;
					pos = j;
					break;
				}
			}
			if (flip_point) {
				rep(j, 0, pos + 1) if (s[i][j] == '?') s[i][j] = s[i - 1][j];
				rep(j, pos + 1, sz(s[i])) if (s[i][j] == '?') s[i][j] = '0';
			} else {
				bool changed = false;
				per(j, pos + 1, sz(s[i])) if (s[i][j] == '?') s[i][j] = '0';
				per(j, 0, pos + 1) {
					if (s[i][j] == '?') {
						if (changed) s[i][j] = s[i - 1][j];
						else if (s[i - 1][j] == '9') s[i][j] = '0';
						else {
							s[i][j] = s[i - 1][j] + 1;
							changed = true;
						}
					}
				}					
			}
			if (s[i] <= s[i - 1]) return cout << "NO", 0;
		}
	}
	
	cout << "YES\n";
	rep(i, 0, n) cout << s[i] << '\n';
}