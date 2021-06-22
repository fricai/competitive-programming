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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17, M = 1e9 + 7;
int f[N], fi[N];

int mul(ll a, int b) {
	return a * b % M;
}
int add(int a, int b) {
	return a += b, a < M ? a : a - M;
}
int sub(int a, int b) {
	return a -= b, a < 0 ? a + M : a;
}

int bpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1) res = mul(res, a);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = 1;
	rep(i, 1, N) f[i] = mul(f[i - 1], i);
	fi[N - 1] = bpow(f[N - 1], M - 2);
	per(i, 1, N) fi[i - 1] = mul(fi[i], i);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	ll s = accumulate(all(a), 0ll);
	if (s % n != 0) return cout << "0\n", 0;
	
	auto cmp = a;
	sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));
	for (auto &x : a) x = lb(all(cmp), x) - begin(cmp);
	
	int fin = s / n;
	vector<int> freq(n);
	
	int sink = 0, src = 0;
	rep(i, 0, n) {
		if (cmp[a[i]] != fin) ++freq[a[i]];
		sink += cmp[a[i]] < fin;
		src += cmp[a[i]] > fin;
	}
	
	if (src <= 1 || sink <= 1) {
		int ans = f[n];
		for (auto x : freq)
			ans = mul(fi[x], ans);
		ans = mul(ans, fi[n - (src + sink)]);
		return cout << ans, 0;
	}
	
	int ans = mul(f[sink], f[src]);
	for (auto x : freq)
		ans = mul(fi[x], ans);
	ans = mul(ans, mul(f[n], mul(fi[src + sink], fi[n - (src + sink)])));
	cout << add(ans, ans) << '\n';	
}