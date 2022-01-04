#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	if (is_sorted(all(s))) {
		return void(cout << "0\n");
	}

	vector<int> z, o;
	rep(i, 0, n)
		if (s[i] == '0') z.push_back(i);
		else o.push_back(i);

	reverse(all(o));

	vector<int> f, b;
	while (!o.empty() && !z.empty()) {
		int i = o.back(); o.pop_back();
		int j = z.back(); z.pop_back();
		if (j < i) break;
		f.push_back(i);
		b.push_back(j);
	}
	reverse(all(b));

	cout << "1\n" << sz(f) + sz(b) << ' ';
	for (auto x : f) cout << x + 1 << ' ';
	for (auto x : b) cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
