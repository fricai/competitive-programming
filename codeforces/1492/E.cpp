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

int diff(const vector<int> &a, const vector<int> &b) {
	int res = 0;
	rep(i, 0, sz(a)) if (a[i] != 0 && b[i] != 0 && a[i] != b[i]) ++res;
	return res;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<int>> t(n, vector<int>(m));
	for (auto &z : t) for (auto &y : z) cin >> y;

	auto first = t[0];
	int mx = 0;
	rep(i, 1, n) ckmax(mx, diff(first, t[i]));
	if (mx > 4) return cout << "No", 0;

	int huh = 0;
	rep(i, 1, n) if (mx == diff(first, t[i])) { huh = i; break; }

	vector<int> diff_points;
	rep(i, 0, m) if (first[i] != t[huh][i]) diff_points.push_back(i);

	rep(S, 0, 1 << mx) {
		if (__builtin_popcount(S) > 2) continue;
		
		auto target = first;

		auto check = [&]() {
			rep(k, 1, n) if (diff(target, t[k]) > 2) return false;
			return true;
		};

		vector<int> yus;
		rep(i, 0, mx) if (S >> i & 1) target[diff_points[i]] = 0, yus.push_back(diff_points[i]);
		
		auto f = [&]() {
			vector<int> can_differ(n);
			rep(i, 1, n) {
				can_differ[i] = 2 - diff(target, t[i]);
				if (can_differ[i] < 0) return false;
			}
			
			rep(i, 1, n) if (can_differ[i] == 0) {
				for (auto x : yus) target[x] = t[i][x];
				return check();
			}
			
			if (sz(yus) <= 1) return true;

			rep(i, 1, n) {
				if (can_differ[i] == 1) {
					rep(b, 0, 2) {
						int x = yus[b], y = yus[!b];
						target[x] = t[i][x];
						
						bool changed = false;
						rep(k, 1, n) {
							if (i != k) {
								if (can_differ[k] == 2) continue;
								if (t[k][x] != target[x]) {
									target[y] = t[k][y];
									changed = true;
									break;
								}		
							}
						}
						if (!changed) target[y] = 555;
						if (check()) return true;
					}
					return false;
				}
			}
			return true;
		};

		if (f()) {
			cout << "Yes\n";
			for (auto &x : target) if (x == 0) x = 555;
			for (auto x : target) cout << x << ' ';
			cout << '\n';
			return 0;
		}
	}
	
	cout << "No";
}