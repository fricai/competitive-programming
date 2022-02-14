#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a);)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1 << 20;
ll t[N << 1];

int n;
void modify(int l, int r, ll value) {
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) t[l++] += value;
		if (r & 1) t[--r] += value;
	}
}

auto query(int p) {
	ll res = 0;
	for (p += n; p > 0; p >>= 1) res += t[p];
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> n >> q;
	set<pair<int, int>> s;
	s.insert({0, 0});
	s.insert({n, 0});

	const auto get_interval = [&](int x) { return prev(s.lower_bound({x, n})); };
	const auto get_col = [&](int x) { return get_interval(x)->second; };

	vector<ll> lazy(n);
	while (q--) {
		string type;
		cin >> type;

		if (type == "Color") {
			int l, r, c; cin >> l >> r >> c; --l; --c;

			auto add = [&](int l, int r, int init_c) {
				modify(l, r, lazy[init_c] - lazy[c]);
			};

			for (int x = l; x < r;) {
				const auto it = get_interval(x);
				const auto [a, init_c] = *it;
				const auto b = next(it)->first;
				// it corresponds [a, b)
				s.erase(it);
				if (x != a) s.insert({a, init_c});
				if (r <= b) {
					add(x, r, init_c);
					if (r != b) s.insert({r, init_c});
				} else
					add(x, b, init_c);
				x = b;
			}

			s.insert({l, c});
		} else if (type == "Add") {
			int c, x; cin >> c >> x; --c;
			lazy[c] += x;
		} else {
			assert(type == "Query");
			int i; cin >> i; --i;
			cout << query(i) + lazy[get_col(i)] << '\n';
		}
	}
}
