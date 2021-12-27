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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


vector<int> solve() {
	int n; cin >> n;

	auto barring = [&](vector<int> v) {
		vector<int> res;
		res.reserve(n);
		for (int i = 1; i <= n; ++i)
			if (find(all(v), i) == end(v))
				res.push_back(i);
		return res;
	};

	if (n % 4 == 0)
		return barring({n / 2});

	using hsh_t = uint64_t;
	vector<hsh_t> h(n + 1);
	{
		vector<int> pf(n + 1);
		for (int p = 2; p <= n; ++p) {
			if (pf[p] != 0)
				continue;
			for (int j = p; j <= n; j += p)
				pf[j] = p;
		}

		for (int p = 2; p <= n; ++p) {
			if (pf[p] == p) h[p] = rng();
			else h[p] = h[p / pf[p]] ^ h[pf[p]];
		}
		for (int i = 2; i <= n; ++i)
			h[i] ^= h[i - 1];
	}

	hsh_t total = 0;
	for (int i = 2; i <= n; ++i)
		total ^= h[i];

	if (total == 0)
		return barring({});

	for (int i = 2; i <= n; ++i)
		if (total == h[i])
			return barring({i});

	if (n % 2 == 0)
		return barring({2, n / 2});

	map<hsh_t, int> mp;
	for (int i = 2; i <= n; ++i) {
		if (auto it = mp.find(h[i] ^ total); it != end(mp))
			return barring({i, it->second});
		mp[h[i]] = i;
	}
	return barring({2, n / 2, n});
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto v = solve();
	cout << sz(v) << '\n';
	for (auto x : v)
		cout << x << ' ';
	cout << '\n';
}
