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

const int A = 10;
bool full[A];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) {
		char c; cin >> c;
		if (c == 'L') {
			rep(i, 0, A) {
				if (!full[i]) {
					full[i] = true;
					break;
				}
			}
		} else if (c == 'R') {
			per(i, 0, A) {
				if (!full[i]) {
					full[i] = true;
					break;
				}
			}
		} else full[c - '0'] = 0;
	}

	rep(i, 0, A) cout << full[i];
}