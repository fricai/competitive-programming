#include <bits/stdc++.h>
#include <atcoder/string>

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

struct ds {
	priority_queue<pair<int, int>> q;

	ll ans = 0;
	void insert(int x) {
		// do y = min(y, x) for all y in ds and add x
		int cur = 1;
		while (!q.empty()) {
			auto [r, z] = q.top();
			if (r < x) break;
			q.pop();
			cur += z;
			ans -= 1ll * r * z;
		}
		q.push({x, cur});
		ans += 1ll * x * cur;
	}

	ll query() { return ans; }
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;

	auto sa = atcoder::suffix_array(s);
	auto lcp = atcoder::lcp_array(s, sa);

	vector<ll> ans(n);
	iota(rall(ans), 1);

	// brute
	
	/*
	rep(i, 0, n) {
		auto &sum = ans[sa[i]];
		for (int j = i, mn = n; j + 1 < n; ++j) {
			uin(mn, lcp[j]);
			sum += mn;
		}
		for (int j = i - 1, mn = n; j >= 0; --j) {
			uin(mn, lcp[j]);
			sum += mn;
		}
	}
	*/

	ds a, b;
	per(i, 0, n - 1) {
		a.insert(lcp[i]);
		ans[sa[i]] += a.query();
	}
	rep(i, 1, n) {
		b.insert(lcp[i - 1]);
		ans[sa[i]] += b.query();
	}

	for (auto x : ans)
		cout << x << '\n';
}
