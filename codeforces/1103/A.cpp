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

bool g[4][4];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	string s; cin >> s;
	for (auto c : s) {
		bool b = c != '1';
		if (b) {
			bool done = false;
			rep(j, 0, 4) {
				rep(i, 0, 3) {
					if (!g[i][j] && !g[i + 1][j]) {
						g[i][j] = g[i + 1][j] = 1;
						cout << i + 1 << ' ' << j + 1 << '\n';
						done = true;
						break;
					}
				}
				if (done) break;
			}
		} else {
			bool done = false;
			per(j, 0, 3) {
				rep(i, 0, 4) {
					if (!g[i][j] && !g[i][j + 1]) {
						g[i][j] = g[i][j + 1] = 1;
						cout << i + 1 << ' ' << j + 1 << '\n';
						done = true;
						break;
					}
				}
				if (done) break;
			}
		}
		
		vector<int> to_delete;
		rep(i, 0, 4) {
			bool del = true;
			rep(j, 0, 4) del &= g[i][j];
			if (del) to_delete.push_back(i);
		}
		rep(j, 0, 4) {
			bool del = true;
			rep(i, 0, 4) del &= g[i][j];
			if (del) rep(i, 0, 4) g[i][j] = 0;
		}
		for (auto i : to_delete)
			rep(j, 0, 4) g[i][j] = 0;
	}
}