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

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	int s = accumulate(all(a), 0);

	int q = s % k, p = s / k;
	if (q == 0) q = k;
	else ++p;

	if (*max_element(all(a)) > p || count(all(a), p) > q)
		return cout << "-1\n", 0;

	vector<int> v;
	while (s > 0) {
		vector<int> blocked(n);
		auto lst = vector(end(v) - min(k - 1, sz(v)), end(v));
		for (auto x : lst) blocked[x] = 1;

		int i = 0;
		if (count(all(a), p) == q) {
			while (a[i] != p || blocked[i]) ++i;
		} else {
			while (a[i] == 0 || blocked[i]) ++i;
		}

		v.push_back(i);
		--a[i];
		--s;
		--q;
		if (q == 0) q = k, --p;
	}

	rep(i, 0, n) {
		while (a[i] != 0) {
			v.push_back(i);
			--a[i];
		}
	}

	for (auto x : v)
		cout << x + 1 << ' ';
	cout << '\n';
}
