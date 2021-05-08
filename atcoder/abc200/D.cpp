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

const int M = 200, N = 200 + 5;
vector<int> st[N][M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x, x %= M;

	auto print = [&](vector<int> p, vector<int> q) {
		assert(!p.empty() && !q.empty());

		int res = 0;
		for (auto i : p) res = (res + a[i]) % M;
		for (auto i : q) res = (res - a[i]) % M;
		assert(res == 0);

		cout << "Yes\n";

		cout << sz(p) << ' ';
		for (auto i : p) cout << i + 1 << ' ';
		cout << '\n';
		
		cout << sz(q) << ' ';
		for (auto i : q) cout << i + 1 << ' ';
		cout << '\n';
		
		exit(0);
	};


	rep(i, 0, n) {
		rep(x, 0, M) st[i + 1][x] = st[i][x];

		rep(x, 0, M) {
			if (x && st[i][x].empty()) continue;

			int nxt = (x + a[i]) % M;
			if (!st[i + 1][nxt].empty()) {
				st[i][x].push_back(i);
				print(st[i + 1][nxt], st[i][x]);
			}
		}

		assert(st[i + 1][a[i]].empty());
		st[i + 1][a[i]] = {i};
		
		rep(x, 1, M) {
			if (st[i][x].empty()) continue;
			
			int nxt = (x + a[i]) % M;

			st[i + 1][nxt] = st[i][x];
			st[i + 1][nxt].push_back(i);
		}	
	}

	cout << "No\n";
}