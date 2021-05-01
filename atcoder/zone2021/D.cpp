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

	deque<char> q;
	
	bool rev = 0;
	for (auto c : s) {
		if (c == 'R') rev ^= 1;
		else {
			if (rev) q.push_front(c);
			else q.push_back(c);
		}
	}
	if (rev) reverse(all(q));
	
	vector<char> st;
	for (auto c : q)
		if (st.empty() || st.back() != c) st.push_back(c);
		else st.pop_back();
	
	for (auto x : st) cout << x;
	cout << '\n';
}