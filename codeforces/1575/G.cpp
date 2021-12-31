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

constexpr int mod = 1e9 + 7, X = 1e5 + 5;
int mul(ll x, int y) { return x * y % mod; }
int add(int x, int y) { x += y; return x < mod ? x : x - mod; }
int sub(int x, int y) { x -= y; return x < 0 ? x + mod : x; }
void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }

int phi[X];
vector<int> divisors[X];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	iota(all(phi), 0);
	for (int i = 2; i < X; ++i)
		if (phi[i] == i)
			for (int j = i; j < X; j += i)
				phi[j] -= phi[j] / i;

	for (int i = 1; i < X; ++i)
		for (int j = i; j < X; j += i)
			divisors[j].push_back(i);


	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	a.insert(begin(a), 0);

	vector<int> cnt(X);

	int ans = 0;
	for (int d = 1; d <= n; ++d) {
		vector<int> to_count;
		for (int i = d; i <= n; i += d)
			for (auto x : divisors[a[i]])
				if (cnt[x]++ == 0)
					to_count.push_back(x);

		int cur = 0;
		for (auto e : to_count) {
			inc(cur, mul(phi[e], mul(cnt[e], cnt[e])));
			cnt[e] = 0;
		}
		inc(ans, mul(phi[d], cur));
	}
	cout << ans << '\n';
}
