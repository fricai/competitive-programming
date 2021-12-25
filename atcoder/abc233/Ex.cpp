#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


constexpr int X = 1 << 18;
vector<int> t[X << 1];

int lol = 0;
void insert(int x, int y) {
	for (x += X; x > 0; x >>= 1) {
		t[x].push_back(y);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &[x, y] : p) {
		cin >> x >> y;
		tie(x, y) = pair(x + y, x - y);
		insert(x, y);
	}
	rep(i, 0, X << 1) sort(all(t[i]));

	auto count = [&](int lo, int hi, int down, int up) -> int {
		int ans = 0;
		++hi;

		auto query = [&](const auto &rec, int v, int l, int r) -> void {
			if (hi <= l || r <= lo)
				return;
			if (lo <= l && r <= hi) {
				ans += lower_bound(all(t[v]), up + 1) - lower_bound(all(t[v]), down);
				return;
			}
			int m = (l + r)/2;
			rec(rec, v << 1|0, l, m);
			rec(rec, v << 1|1, m, r);
		};
		query(query, 1, 0, X);
		return ans;
	};

	int q; cin >> q;
	while (q--) {
		int a, b, k; cin >> a >> b >> k;
		tie(a, b) = pair(a + b, a - b);

		int l = -1, r = 1e6;
		// -1 is not possible
		while (r - l > 1) {
			int d = (l + r) / 2;
			if (count(a - d, a + d, b - d, b + d) < k) l = d;
			else r = d;
		}
		cout << r << '\n';
	}
}
