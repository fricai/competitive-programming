#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 11, A = 26;
int f[A];

int solve() {
	int n, k; cin >> n >> k;
	fill(f, f + A, 0);
	rep(i, 0, n) {
		char c; cin >> c;
		++f[c - 'a'];
	}

	int ans = 1;
	for (int m = 1; m <= n; ++m) {
		int g = gcd(k, m);

		priority_queue<int> pq;
		rep(a, 0, A) pq.push(f[a]);

		bool ok = true;
		rep(i, 0, g) {
			int t = pq.top(); pq.pop();
			if (t < m / g) {
				ok = false;
				break;
			}
			t -= m / g;
			pq.push(t);
		}
		if (ok) ans = m;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';	
}