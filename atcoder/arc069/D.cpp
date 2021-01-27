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
bool v[N], s[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;
	rep(b, 0, 2) {
		v[0] = b;
		rep(c, 0, 2) {
			v[1] = c;
			rep(i, 2, n) {
				if (v[i - 1] == 0) {
					// v[i - 1] is sheep
					if (s[i - 1] == 'o') v[i] = v[i - 2];
					else v[i] = !v[i - 2];
				} else {
					if (s[i - 1] == 'o') v[i] = !v[i - 2];
					else v[i] = v[i - 2];
				}
			}
			bool fine = true;
			rep(i, 0, n) {
				if (v[i] == 0) { // v[i] is sheep
					if (s[i] == 'o') {
						if (v[(i + n - 1) % n] != v[(i + 1) % n]) fine = false;
					} else if (v[(i + n - 1) % n] == v[(i + 1) % n]) fine = false;
				} else {
					if (s[i] == 'x') {
						if (v[(i + n - 1) % n] != v[(i + 1) % n]) fine = false;
					} else if (v[(i + n - 1) % n] == v[(i + 1) % n]) fine = false;
				}
			}
			if (fine) {
				rep(i, 0, n) cout << (v[i] ? "W" : "S");
				return 0;
			}
		}
	}
	cout << -1;
}