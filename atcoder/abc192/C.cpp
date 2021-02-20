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

const int B = 10;

int f(int x) {
	if (x == 0) return 0;
	string s;
	while (x) {
		s += char('0' + (x % B));
		x /= B;
	}
	sort(all(s));
	string t(rall(s));
	// cerr << s << ' ' << t << '\n';
	return stoi(t) - stoi(s);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k; cin >> n >> k;
	rep(i, 0, k) n = f(n);
	cout << n;
}