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

	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<int> q, st;
	
	int lo = 0, hi = 0;
	rep(i, 1, n) if (s[i - 1] == 'R' && s[i] == 'L') q.push_back(i);
	
	string t = s;

	while (!q.empty()) {
		while (!q.empty()) {
			int i = q.back(); q.pop_back();
			s[i - 1] = 'L';
			s[i] = 'R';
			if (i - 1 > 0) if (s[i - 2] == 'R') st.push_back(i - 1);
			if (i + 1 < n) if (s[i + 1] == 'L') st.push_back(i + 1);
			++hi;
		}
		++lo;

		sort(all(st)); st.erase(unique(all(st)), end(st));
		swap(q, st);
	}
	
	if (k < lo || k > hi) return cout << -1, 0;
	
	s = t;
	rep(i, 1, n) if (s[i - 1] == 'R' && s[i] == 'L') q.push_back(i);

	while (!q.empty()) {
		vector<int> op;
		while (!q.empty() && k <= hi) {
			int i = q.back(); q.pop_back();
			op.push_back(i);
			s[i - 1] = 'L';
			s[i] = 'R';
			if (i - 1 > 0) if (s[i - 2] == 'R') st.push_back(i - 1);
			if (i + 1 < n) if (s[i + 1] == 'L') st.push_back(i + 1);
			--hi;
		}
		--k;
		cout << sz(op) << ' ';
		for (auto x : op) cout << x << ' ';
		cout << '\n';

		sort(all(st)); st.erase(unique(all(st)), end(st));
		q.insert(end(q), all(st));
		st.clear();
	}
}