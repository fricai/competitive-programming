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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, l, r; cin >> n >> l >> r;
		vector<int> L(n), R(n);
		rep(i, 0, n) {
			int c; cin >> c;
			++(i < l ? L : R)[--c];
		}

		vector<int> S[2][2];
		auto add = [&](int i) {
			if (L[i] == R[i]) return;
			S[L[i] % 2 != R[i] % 2][R[i] > L[i]].push_back(i);
		};

		rep(i, 0, n) add(i);
		
		int ans = 0;
		while (!S[1][0].empty() && !S[1][1].empty()) {
			int lef = S[1][0].back();
			int rig = S[1][1].back();
			--L[lef];
			++L[rig];
			++ans;
			S[1][0].pop_back();
			S[1][1].pop_back();
			add(lef);
			add(rig);
		}
		
		assert(S[1][0].empty() || S[1][1].empty());
		if (!S[1][0].empty()) {
			assert(sz(S[1][0]) % 2 == 0);
			while (!S[1][0].empty()) {
				// 0 -> L[i] > R[i]
				int i = S[1][0].back();
				S[1][0].pop_back();

				int j = S[1][0].back();
				S[1][0].pop_back();

				if (!S[0][1].empty()) {
					int k = S[0][1].back();
					S[0][1].pop_back();
					L[k] += 2;
					--L[i];
					--L[j];
					ans += 2;
					add(k);
				} else {
					++L[i];
					--L[j];
					++ans;
				}

				add(i);
				add(j);
			}
		} else {
			assert(sz(S[1][1]) % 2 == 0);
			while (!S[1][1].empty()) {
				int i = S[1][1].back();
				S[1][1].pop_back();

				int j = S[1][1].back();
				S[1][1].pop_back();

				if (!S[0][0].empty()) {
					int k = S[0][0].back();
					S[0][0].pop_back();
					R[k] += 2;
					--R[i];
					--R[j];
					ans += 2;
					add(k);
				} else {
					++R[i];
					--R[j];
					++ans;
				}
				add(i);
				add(j);
			}
		}
		
		rep(b, 0, 2) {
			while (!S[0][b].empty()) {
				int i = S[0][b].back();
				S[0][b].pop_back();
				ans += abs(R[i] - L[i]) / 2;
			}
		}
		
		cout << ans << '\n';
	}
}