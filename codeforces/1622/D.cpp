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

constexpr int mod = 998244353, N = 5e3 + 10;
int fac[N], inv[N], ifac[N];
int mul(ll x, int y) { return x * y % mod; }
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }

int C(int x, int y) {
	if (y < 0 || y > x) return 0;
	return mul(fac[x], mul(ifac[y], ifac[x - y]));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
	rep(i, 2, N) {
		inv[i] = mod - mul(mod / i, inv[mod % i]);
		fac[i] = mul(i, fac[i - 1]);
		ifac[i] = mul(inv[i], ifac[i - 1]);
	}

	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<pair<int, int>> v;

	int ans = 1;
	for (int l = 0, r = 0, sum = 0; l < n; ++l) {
		while (r < n && sum < k) sum += s[r++] == '1';
		if (sum < k) continue;
		while (r < n && s[r] == '0') ++r;
		if (l == 0 || s[l - 1] == '1') {
			inc(ans, C(r - l, k) - 1);
			if (!v.empty()) {
				auto [x, y] = v.back();
				if (l < y) {
					int num = count(begin(s) + l, begin(s) + y, '1');
					dec(ans, C(y - l, num) - 1);
				}
			}
			v.emplace_back(l, r);
		}
		sum -= s[l] == '1';
	}
	cout << ans << '\n';
}
