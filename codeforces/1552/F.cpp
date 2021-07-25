#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 119 << 23 | 1;

int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
			
	int n; cin >> n;
	vector<int> p(n + 1), x(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int y, s; cin >> x[i] >> y >> s;
		
		int j = upper_bound(begin(x), begin(x) + i, y) - begin(x);
		int cur = add(sub(x[i], y), sub(p[i], p[j]));

		if (s) ans = add(ans, cur);
		p[i + 1] = add(p[i], cur);
	}
	ans = add(ans, add(x.back(), 1));
	cout << ans << '\n';
}