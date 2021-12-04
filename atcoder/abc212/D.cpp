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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	ll shift = 0;
	priority_queue<ll> pq;
	while (q--) {
		int p; cin >> p;
		if (p <= 2) {
			int x; cin >> x;
			if (p == 1) pq.push(shift - x);
			else shift += x;
		} else {
			cout << -pq.top() + shift << '\n';
			pq.pop();
		}
	}
}
