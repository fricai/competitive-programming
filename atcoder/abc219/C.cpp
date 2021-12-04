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

constexpr int A = 26;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string x; int n; cin >> x >> n;
	vector<string> s(n);
	for (auto &r : s) cin >> r;

	int f[A];
	rep(i, 0, A) {
		f[x[i] - 'a'] = i;
	}

	vector<pair<vector<int>, string>> what;
	for (auto r : s) {
		vector<int> v;
		for (auto c : r)
			v.push_back(f[c - 'a']);
		what.emplace_back(v, r);
	}
	sort(all(what));

	for (auto [_, r] : what)
		cout << r << '\n';
}
