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

constexpr int A = 26, N = 1 << 18;

struct inc_segtree {
	int n;
	vector<int> t;
	inc_segtree(int n) : n{n}, t(2 * n, 0) { }
	void modify(int l, int r, int value) {
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) t[l++] += value;
			if (r & 1) t[--r] += value;
		}
	}
	int query(int p) {
		int res = 0;
		for (p += n; p > 0; p >>= 1) res += t[p];
		return res;
	}
};


string f(const string &s, ll k) {
	int n = sz(s);
	array<vector<int>, A> pos;
	per(i, 0, n) pos[s[i] - 'a'].push_back(i);
	vector<int> seen(n);

	inc_segtree t(n);

	string res;
	rep(i, 0, n) {
		if (k == 0)
			break;
		rep(d, 0, A) {
			if (pos[d].empty())
				continue;

			int cur = pos[d].back();
			int count = cur + t.query(cur) - i;
			if (count > k) continue;

			res += s[cur];
			pos[d].pop_back();
			seen[cur] = true;
			t.modify(0, cur, 1);
			k -= count;
			break;
		}
	}
	rep(i, 0, n) if (!seen[i]) res += s[i];
	return res;
}

ll solve() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	if (s < t) return 0;

	{
		string guh = s;
		sort(all(guh));
		if (guh >= t) return -1;
	}

	ll l = 0, r = 1ll * n * (n - 1) / 2;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (f(s, m) < t) r = m;
		else l = m;
	}
	return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
