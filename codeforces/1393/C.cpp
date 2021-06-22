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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 18;

const int inf = 1e9;

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;

	auto ok = [&](int dist) {
		vector<int> cnt(n);
		
		for (auto x : a) ++cnt[x];

		priority_queue<pair<int, int>> q;

		auto add = [&](int i) {
			if (cnt[i]) q.push({cnt[i], i});
		};
		
		rep(i, 0, n) add(i);

		vector<int> cur;
		rep(i, 0, n) {
			if (i > dist) add(cur[i - dist - 1]);
			if (q.empty()) return 0;
			int u = q.top().second; q.pop();
			cur.push_back(u); --cnt[u];
		}
		return 1;
	};

	int l = 0, r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		(ok(m) ? l : r) = m;
	}
	return l;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}