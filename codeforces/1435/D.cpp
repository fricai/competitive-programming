#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 17;
int v[N];

bool solve(int n) {
	vector<pair<bool, int>> inp;
	rep(i, 0, 2 * n) {
		char c; cin >> c;
		int x = 0;
		if (c != '+') cin >> x;
		inp.emplace_back(c == '+', x);
	}

	stack<int> s; int i = 0;
	for (auto [b, x] : inp) {
		if (b) s.push(i++);
		else {
			if (s.empty()) return false;
			v[s.top()] = x;
			s.pop();
		}
	}

	priority_queue<int> pq; i = 0;
	for (auto [b, x] : inp) {
		if (b) pq.push(-v[i++]);
		else {
			if (pq.top() != -x) return false;
			pq.pop();
		}
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	if (solve(n)) {
		cout << "YES\n";
		rep(i, 0, n) cout << v[i] << ' ';
	} else cout << "NO";
}