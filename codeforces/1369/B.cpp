#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

bool dead[1 << 17];

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int front_zeroes = 0;
	while (s[front_zeroes] == '0') ++front_zeroes;

	int last_ones = n - 1;
	while (s[last_ones] == '1') --last_ones;

	if (last_ones + 1 == front_zeroes) return void(cout << s << '\n');
	rep(i, 0, front_zeroes) cout << s[i];
	rep(i, last_ones, n) cout << s[i];
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}