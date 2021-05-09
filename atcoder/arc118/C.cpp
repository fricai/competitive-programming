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

const int MAX = 10'000;
bool taken[MAX + 1];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	
	vector<int> v;
	auto add = [&](int x) {
		if (taken[x]) return;
		taken[x] = 1;
		v.push_back(x);
	};
	add(6); add(10); add(15);
	
	auto init = v;
	for (auto d : init)
		for (int x = d + d; x <= MAX && sz(v) < n; x += d)
			add(x);

	for (auto x : v) cout << x << ' ';
	cout << '\n';
}