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

const int N = 1 << 17, M = 2 * N;
int a[M], b[M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<pair<int, int>> v(m);
	for (auto &[a, b] : v) {
		cin >> a >> b; --a; --b;
		if (a > b) swap(a, b);
	}
	sort(all(v));

	for (int d = 1; d < n; ++d) {
		if (n % d) continue;
		vector<pair<int, int>> w;
		for (auto [a, b] : v)
			w.emplace_back((a + d) % n, (b + d) % n);
		for (auto &[a, b] : w)
			if (a > b) swap(a, b);
		sort(all(w));
		if (v == w) return cout << "Yes\n", 0;
	}
	cout << "No\n";
}