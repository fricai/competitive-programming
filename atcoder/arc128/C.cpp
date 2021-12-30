#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll m, s; cin >> n >> m >> s;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	vector<ll> b(n + 1);
	per(i, 0, n) b[i] = b[i + 1] + a[i];
	reverse(all(b));

	double ans = 0;
	for (int p = 0; p < n; ) {
		int j = p + 1;
		for (int i = p + 1; i <= n; ++i)
			if ((b[j] - b[p]) * (i - p) < (j - p) * (b[i] - b[p]))
				j = i;

		if (s <= m * (j - p)) {
			ans += double((b[j] - b[p]) * s) / (j - p);
			break;
		} else {
			ans += (b[j] - b[p]) * m;
			s -= m * (j - p);
			p = j;
		}
	}

	cout << fixed << setprecision(20) << ans << '\n';
}
