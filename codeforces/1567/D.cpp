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

template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;


const int inf = 1e9;
void solve() {
	int s, n; cin >> s >> n;

	for (int p = inf; n > 1; p /= 10) {
		while (n > 1 && s - p >= n - 1) {
			cout << p << ' ';
			s -= p;
			--n;
		}
	}
	cout << s << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
