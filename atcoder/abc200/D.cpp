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

const int M = 200;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x, x %= M;

	int m = min(8, n);
	auto print = [&](int S) {
		cout << __builtin_popcount(S) << ' ';
		rep(i, 0, m) if (S >> i & 1) cout << i + 1 << ' ';
		cout << '\n';
	};
	
	vector<int> oth(M);
	rep(S, 1, 1 << m) {
		int res = 0;
		rep(i, 0, m) if (S >> i & 1) {
			res += a[i];
			if (M <= res) res -= M;
		}

		if (oth[res]) {
			cout << "Yes\n";
			print(S);
			print(oth[res]);
			return 0;
		} else oth[res] = S;
	}

	cout << "No\n";
}