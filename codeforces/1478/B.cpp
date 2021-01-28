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

const int B = 10, N = 1 << 10;
bool lucky[B][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 1, B) lucky[i][0] = 1;
	rep(i, 1, N) {
		rep(j, 1, i + 1) {
			int m = j;
			while (m) {
				lucky[m % B][i] |= lucky[m % B][i - j];
				m /= B;
			}
		}
	}

	int t; cin >> t;
	while (t--) {
		int q, d; cin >> q >> d;
		while (q--) {
			int x; cin >> x;
			cout << (x >= N || lucky[d][x] ? "YES" : "NO") << '\n';
		}
	}
}