#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define lb(x...) lower_bound(x)

using ll = long long;
using point = complex<double>;

vector<point> p;

const int N = 1 << 18;
double tau = 2 * acos(-1);

int n, t[N << 1];
void flip(int p) {
	for (t[p += n] ^= 1; p >>= 1; )
		t[p] = t[p << 1] + t[p << 1|1];
}

int sum(int l, int r) {
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

ll cnt(double r) {
	vector<pair<double, double>> tmp;
	vector<pair<double, int>> cmp; n = 0;

	for (auto &z : p) {
		auto d = abs(z);
		if (d <= r) continue;
		double theta = arg(z);
		double del = acos(r / d);
		assert(del > 0);
		auto a = theta - del, b = theta + del;
		if (a < 0) a += tau;
		if (b < 0) b += tau;
		if (a > b) swap(a, b);
		tmp.emplace_back(a, b);
		cmp.emplace_back(a, -n); cmp.emplace_back(b, +n);
		n += 2;
	}
	sort(all(cmp));

	fill(t, t + 2 * n, 0);
	vector<int> I(n);

	ll res = 0;
	int i = 0;
	for (auto &[a, b] : tmp) {
		int x = lb(all(cmp), pair(a, -i)) - begin(cmp);
		int y = lb(all(cmp), pair(b, +i)) - begin(cmp);
		assert(x < y);
		I[x] = I[y] = x;
		i += 2;
	}

	rep(i, 0, n) {
		flip(I[i]);
		if (I[i] != i) res += sum(I[i], n);
	}

	return res;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n; ll k; cin >> n >> k;
	p.resize(n);
	for (auto &z : p) {
		double x, y; cin >> x >> y;
		z = {x, y};
	}

	ll tot = 1ll * n * (n - 1) / 2;
	double l = 0, r = 2e4;
	rep(i, 0, 50) {
		auto m = (l + r) / 2;
		(tot - cnt(m) < k ? l : r) = m;
	}
	cout << fixed << setprecision(10) << l << '\n';
}