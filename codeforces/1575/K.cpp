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

constexpr int M = 1e9 + 7;

pair<ll, ll> f(pair<int, int> a, pair<int, int> b, ll r, ll c) {
	if (a > b) swap(a, b);

	ll inter_r = 0, inter_c = 0;
	ll inter_union = 0, add = 0;

	if (b.first < a.first + r) {
		inter_r = a.first + r - b.first;

		pair<int, int> p;
		p.first = b.first;

		if (a.second < b.second) {
			p.second = b.second;
			inter_c = max(0ll, a.second + c - b.second);
		} else {
			p.second = a.second;
			inter_c = max(0ll, b.second + c - a.second);
		}

		auto q = p;
		q.first += a.first - b.first;
		q.second += a.second - b.second;

		if (inter_r > 0 && inter_c > 0) {
			tie(add, inter_union) = f(q, p, inter_r, inter_c);
		}
	}

	return {r * c - inter_union + add, 2 * r * c - inter_r * inter_c};
}

int bpow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = a * a % M)
		if (b & 1)
			res = res * a % M;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, k, r, c; cin >> n >> m >> k >> r >> c;
	int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;

	ll x, y;
	if (ax != bx || ay != by)
		tie(x, y) = f({ax, ay}, {bx, by}, r, c);
	else
		x = y = r * c;

	cout << bpow(k, n * m - y + x) << '\n';
}
