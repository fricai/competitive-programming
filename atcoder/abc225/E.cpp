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

using P = complex<ll>;
bool compare(const P &a, const P &b) { return imag(conj(a) * b) > 0; }
P normalize(P p) {
	auto g = gcd(real(p), imag(p));
	return {real(p) / g, imag(p) / g};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<P> cmp;
	vector<pair<int, int>> ps(n);
	for (auto &[x, y] : ps)
		cin >> x >> y;

	for (auto [x, y] : ps) {
		cmp.push_back(normalize({x - 1, y}));
		cmp.push_back(normalize({x, y - 1}));
	}

	sort(all(cmp), compare); cmp.erase(unique(all(cmp)), end(cmp));

	vector<pair<int, int>> I;
	for (auto [x, y] : ps) {
		auto a = normalize({x, y - 1});
		int l = lower_bound(all(cmp), a, compare) - begin(cmp);
		auto b = normalize({x - 1, y});
		int r = lower_bound(all(cmp), b, compare) - begin(cmp);
		I.emplace_back(r, l);
	}

	sort(all(I));

	int lst = 0, ans = 0;
	for (auto [x, y] : I) {
		if (lst <= y) {
			lst = x;
			++ans;
		}
	}
	cout << ans << '\n';
}
