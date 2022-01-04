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

	int n; cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<int> b(n);
	for (auto &x : b) cin >> x;
	a.insert(begin(a), 0);
	b.insert(begin(b), 0);

	vector<int> mu(n + 1);
	mu[1] = 1;
	for (int j = 1; j <= n; ++j)
		for (int i = j + j; i <= n; i += j) 
			mu[i] -= mu[j];

	vector<ll> p(n + 1);
	for (int i = 2; i <= n; ++i) {
		p[i] += b[i] - a[i];
		for (int j = i + i; j <= n; j += i)
			p[j] -= p[i];
	}

	ll shift = 0;
	struct {
		int n;
		vector<ll> a, p;
		void add(ll x) { a.push_back(x); }
		void init() {
			sort(all(a));
			n = sz(a);
			p.resize(n + 1);
			for (int i = 0; i < n; ++i)
				p[i + 1] = p[i] + a[i];
		}
		ll evaluate(ll x) {
			int j = lower_bound(all(a), x) - begin(a);
			return ((p[n] - p[j]) - (n - j) * x) + (j * x - p[j]);
		}
	} pos, neg;

	for (int i = 1; i <= n; ++i) {
		if (mu[i] > 0) pos.add(p[i]);
		if (mu[i] < 0) neg.add(p[i]);
		if (mu[i] == 0) shift += abs(p[i]);
	}
	pos.init();
	neg.init();

	int q; cin >> q;
	while (q--) {
		ll x; cin >> x; x -= a[1];
		cout << shift + pos.evaluate(-x) + neg.evaluate(+x) << '\n';
	}
}
