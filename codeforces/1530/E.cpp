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

const int A = 26;

string solve() {
	string s; cin >> s;
	int n = sz(s);
	
	if (n == 1)
		return s;

	vector<int> f(A);
	for (auto x : s) ++f[x - 'a'];

	for (auto x : f)
		if (x == n)
			return s;
	
	string t;
	auto add = [&](int x) {
		--f[x];
		t.push_back(x + 'a');
	};
	
	rep(i, 0, A) {
		if (f[i] != 1) continue;
		add(i);
		rep(j, 0, A)
			while (f[j] > 0)
				add(j);
		return t;
	}
	
	int a = 0;
	while (f[a] == 0) ++a;
	
	if (f[a] - 2 <= (n - 2) / 2) {
		add(a); add(a);
		int i = a + 1;
		while (f[a] > 0) {
			while (f[i] == 0) ++i;
			add(i); add(a);
		}
		while (i < A) {
			while (f[i] > 0)
				add(i);
			++i;
		}
		return t;
	}
	
	int b = a + 1;
	while (f[b] == 0) ++b;
	add(a); add(b);
	
	int c = b + 1;
	while (c < A && f[c] == 0) ++c;
	
	if (c < A) {
		while (f[a] > 0) add(a);
		add(c);
		rep(i, a + 1, A)
			while (f[i] > 0)
				add(i);
	} else {
		while (f[b] > 0) add(b);
		while (f[a] > 0) add(a);		
	}
	
	return t;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}