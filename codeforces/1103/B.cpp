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

bool ask(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	string res; cin >> res;
	assert(res != "e");
	return res == "x";
}

signed main() {
	while (true) {
		string s; cin >> s;
		if (s != "start") return 0;
		if (ask(0, 1)) {
			cout << "! 1" << endl;
			continue;
		}
		int a = 1;
		while (!ask(a, a << 1)) a <<= 1;
		int l = a, r = a << 1;
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			(ask(m, a) ? l : r) = m;
		}
		cout << "! " << r << endl;
	}
}