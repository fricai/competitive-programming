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

	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &[x, y] : p)
		cin >> x >> y;
	sort(all(p));

	int count = 0;
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			pair a = {p[i].first, p[j].second};
			pair b = {p[j].first, p[i].second};
			if (a != p[i] && b != p[j] && a != p[j] && b != p[i] && a != b) {
				count += binary_search(all(p), a) && binary_search(all(p), b);
			}
		}
	}
	cout << count / 2 << '\n';
}
