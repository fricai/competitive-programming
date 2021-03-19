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

array<int, 4> _cnt;
int n;
bool f(int s) {
	auto cnt = _cnt;
	vector<int> res = {s + 1};
	
	auto g = [&](int x) {
		if (x < 0 || x > 3 || cnt[x] == 0) return 0;
		--cnt[x];
		res.push_back(x);
		return 1;
	};
	
	rep(i, 0, n)
		if (!g(res.back() - 1) && !g(res.back() + 1))
			return 0;
			
	res.erase(begin(res));
	assert(sz(res) == n);

	cout << "YES\n";
	for (auto x : res) cout << x << ' ';
	cout << '\n';
	return 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	for (auto &x : _cnt) cin >> x, n += x;
	
	rep(s, 0, 4) if (f(s)) return 0;
	cout << "NO\n";
}