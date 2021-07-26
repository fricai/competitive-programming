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
	vector<int> q(k);

	rep(step, 0, k) {
		cin >> q[step];
		
		vector<int> ind(q[step]);
		for (auto &x : ind)
			cin >> x, --x;
		reverse(all(ind));
		
		succ[step].assign(q[step] + 1, 0);
		for (int i = 1; i <= q[step]; ++i) {
			S[step] |= p[ind[i - 1]];
			succ[step][i] = S[step];
		}
		
		// cerr << bitset<4>(S[step]) << ": ";
		// for (auto x : succ[step])
		// 	cerr << bitset<5>(x) << ' ';
		// cerr << '\n';
	}
	
	if (n == 1) ok(true);

	vector<bool> vis(n + 1);
	auto rec = [&](const auto &self, ll f, ll T, int step) -> bool {
		if (step == k) {
			int ones = __builtin_popcountll(f);
			vis[ones] = true;
			// first z bits should be 0, rest should be 1
			return (f & ~(p[n - ones] - 1)) == f;
		}

		int new_indices = __builtin_popcountll(S[step] & ~T);
		int min_ones = __builtin_popcountll(S[step] & f);
		ll nxtT = T | S[step];
		
		f &= ~S[step];
		for (int ones = min_ones; ones <= min_ones + new_indices; ++ones)
			if (!self(self, f | succ[step][ones], nxtT, step + 1))
				return false;
		return true;
	};
	
	if (!rec(rec, 0, 0, 0)) ok(false);
	for (auto x : vis)
		if (!x)
			ok(false);
	ok(true);
}