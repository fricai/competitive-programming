#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int A = 21;
vector<int> f[A], to[A], reach[A];

int solve() {
	int n; string a, b;
	cin >> n >> a >> b;

	rep(i, 0, n) if (a[i] > b[i]) return -1;
	rep(i, 0, n) a[i] -= 'a', b[i] -= 'a';

	rep(c, 0, A) f[c].clear(), to[c].clear(), reach[c].clear();
	rep(i, 0, n) if (a[i] != b[i]) f[a[i]].eb(i);

	int ans = 0;
	for (int c = A - 1; 0 <= c; --c) {
		trav(i, f[c]) {
			rep(z, c + 1, A)
				if (z == b[i] || binary_search(all(reach[z]), b[i])) {
						to[c].eb(z);
						break;
				}
		}
		sort(all(to[c])); to[c].resize(unique(all(to[c])) - begin(to[c]));
		reach[c] = to[c];
		trav(z, to[c]) trav(x, reach[z]) reach[c].eb(x);
		sort(all(reach[c])); reach[c].resize(unique(all(reach[c])) - begin(reach[c]));
		ans += sz(to[c]);
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}