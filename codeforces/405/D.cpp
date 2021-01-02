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

const int A = 1e6;
bool f[A + 1];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) {
		int x; cin >> x;
		f[x] = 1;
	}
	vector<int> v;
	for (int j = 1; j <= A; ++j)
		if (j < A + 1 - j && !f[j] && !f[A + 1 - j])
			v.push_back(j);

	vector<int> ans;
	for (int j = 1; j <= A; ++j) {
		if (f[j]) {
			if (!f[A + 1 - j]) ans.push_back(A + 1 - j);
			else {
				f[A + 1 - j] = 0;
				int x = v.back(); v.pop_back();
				ans.push_back(x);
				ans.push_back(A + 1 - x);
			}
		}
	}
	cout << sz(ans) << '\n';
	for (auto x : ans) cout << x << ' ';
}