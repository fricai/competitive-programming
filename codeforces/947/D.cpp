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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct smth {
	vector<int> a, b, cnt;
	smth(string s) {
		int n = sz(s);
		a.assign(n + 1, 0);
		b.assign(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			b[i + 1] = (s[i] == 'B' || s[i] == 'C') + b[i];
			if (s[i] == 'A')
				a[i + 1] = 1 + a[i];
		}
	}
	int l, r;
	void seA(int a, int b) { l = a, r = b; }
	int A() { return min(r - l + 1, a[r]); }
	int B() { return b[r] - b[l - 1]; }
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t; cin >> s >> t;
	smth x(s), y(t);

	int q; cin >> q;
	while (q--) {
		cout << [&]() -> bool {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			// S -> T
			/*
				a -> bb
				b -> ab
				ab -> b
				aaa -> {}
				
				a^k b -> {}
				b -> b^(2k) b
				
			*/

			x.seA(a, b); y.seA(c, d);
			
			
			if (x.B() == y.B())
				return x.A() >= y.A() && (x.A() - y.A()) % 3 == 0;
			
			if (x.B() > y.B() || (x.B() - y.B()) % 2 != 0)
				return 0;
			if (x.A() == y.A())
				return x.B() != 0;
			return x.A() > y.A();
		}();
	}
	cout << '\n';
}