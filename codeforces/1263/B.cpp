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

const int N = 1 << 4;
string p[N];

char nxt(char c) { return (c - '0' + 1) % 10 + '0'; }

void solve() {
	set<int> s;
	
	int n; cin >> n;
	rep(i, 0, n) cin >> p[i];
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		bool another = false;
		for (int j = i + 1; j < n; ++j)
			if (p[i] == p[j]) another = true;
		if (another) continue;
		vector<int> v;
		for (int j = 0; j < i; ++j)
			if (p[i] == p[j]) {
				++cnt;
				bool valid;
				rep(k, 0, 4) {
					rep(v, 0, 10) {
						valid = true;
						p[j][k] = nxt(p[j][k]);
						rep(r, 0, n) if (j != r && p[j] == p[r]) valid = false;
						if (valid) break;
					}
					if (valid) break;
				}
				assert(valid);
			}
	}

	cout << cnt << '\n';
	rep(i, 0, n) cout << p[i] << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}