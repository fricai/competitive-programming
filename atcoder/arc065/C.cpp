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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	for (int i = sz(s); i > 0; ) {
		if (i - 7 >= 0 && s.substr(i - 7, 7) == "dreamer") i -= 7;
		else if (i - 6 >= 0 && s.substr(i - 6, 6) == "eraser") i -= 6;
		else if (i - 5 >= 0 && s.substr(i - 5, 5) == "dream") i -= 5;
		else if (i - 5 >= 0 && s.substr(i - 5, 5) == "erase") i -= 5;
		else return cout << "NO", 0;
	}
	cout << "YES";
}