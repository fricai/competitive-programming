#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d; cin >> n >> d;
	vector<pair<int, int>> I(n);
	for (auto &[l, r] : I)
		cin >> l >> r;
	sort(all(I));
	vector<bool> dead(n);
	priority_queue<pair<int, int>> q;
	rep(i, 0, n) {
		q.push({-I[i].second, i});
	}
	/*
	 * Always pick the interval with left-most right, call this r
	 * then delete all intervals which intersect with [r, r + d - 1]
	 * then repeat
	 */

	int count = 0;
	for (int j = 0; !q.empty(); q.pop()) {
		int i = q.top().second;
		if (dead[i])
			continue;
		while (j < n && I[j].first < I[i].second + d) {
			dead[j] = true;
			++j;
		}
		++count;
	}
	cout << count << '\n';
}
