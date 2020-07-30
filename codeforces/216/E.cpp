#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 17;
ll a[N], c[N];
map<ll, int> freq, freqc;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, b, n; cin >> k >> b >> n; --k;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		c[i] = a[i] + c[i - 1];
		a[i] = c[i] % k;
	}

	ll zero = 0;
	for (int i = 0; i <= n; ++i) zero += freqc[c[i]]++;

	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		int y = (a[i] - b) % k;
		if (y < 0) y += k;
		ans += freq[y];
		++freq[a[i]];
	}

	if (b % k) cout << ans;
	else if (b) cout << ans - zero;
	else cout << zero;
}