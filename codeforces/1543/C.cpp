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

const double eps = 1e-6;

double g(double c, double p, double v) {
	if (abs(p - 1) <= eps) return 1;
	
	double res = 1;

	if (c - v <= eps)
		res += c;
	else
		res += c * g(c - v, p + v, v);
	return res;
}

double f(double c, double m, double p, double v) {
	if (abs(p - 1) <= eps) return 1;
	
	double res = 1;
	
	if (m - v <= eps)
		res += m * g(c + m / 2, p + m / 2, v);
	else
		res += m * f(c + v / 2, m - v, p + v / 2, v);
	
	if (c - v <= eps)
		res += c * g(m + c / 2, p + c / 2, v);
	else
		res += c * f(c - v, m + v / 2, p + v / 2, v);
	
	return res;
}

double solve() {
	double c, m, p, v; cin >> c >> m >> p >> v;
	return f(c, m, p, v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(10);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}