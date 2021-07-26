#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll p[60];

void ok(bool b) {
	cout << (b ? "ACCEPTED" : "REJECTED") << '\n';
	exit(0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 60; ++i)
		p[i] = 1ll << i;
	
	int n, k; cin >> n >> k;

	vector<ll> S(k);
	vector<vector<ll>> succ(k);
	ll fin = 0;
	rep(step, 0, k) {
		int q; cin >> q;
		
		vector<int> ind(q);
		for (auto &x : ind)
			cin >> x, --x;
		reverse(all(ind));
		
		succ[step].assign(q + 1, 0);
		for (int i = 0; i < q; ++i) {
			S[step] |= p[ind[i]];
			succ[step][i + 1] = S[step];
		}
		fin |= S[step];
	}

	if (n == 1) ok(true);
	if (fin != p[n] - 1) ok(false);

	auto rec = [&](const auto &self, ll f, ll T, int step) -> bool {
		if (step == k)
			return (f & ~(p[n - __builtin_popcountll(f)] - 1)) == f;
		
		int new_indices = __builtin_popcountll(S[step] & ~T);
		int min_ones = __builtin_popcountll(S[step] & f);
		ll nxtT = T | S[step];
		
		f &= ~S[step];
		for (int ones = min_ones; ones <= min_ones + new_indices; ++ones)
			if (!self(self, f | succ[step][ones], nxtT, step + 1))
				return false;
		return true;
	};
	
	ok(rec(rec, 0, 0, 0));
}