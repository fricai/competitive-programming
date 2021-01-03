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

const int N = 1 << 18;
int w[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> unfilled, half_filled;
	rep(i, 0, n) cin >> w[i];
	rep(i, 0, n) unfilled.push_back(i);
	sort(all(unfilled), [&](int i, int j) {
		return w[i] > w[j];
	});
		
	rep(i, 0, 2 * n) {
		char c; cin >> c;
		if (c == '0') {
			auto p = unfilled.back(); unfilled.pop_back();
			cout << p + 1 << ' ';
			half_filled.push_back(p);
		} else {
			cout << half_filled.back() + 1 << ' ';
			half_filled.pop_back();
		}
	}
}