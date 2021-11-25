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

constexpr int B = 30;

map<pair<int, int>, int> p, q;

int ask_and(int i, int j) {
	if (i > j) {
		swap(i, j);
	}

	auto it = p.find({i, j});
	if (it != end(p))
		return it->second;

	cout << "and " << i + 1 << ' ' << j + 1 << endl;

	int x; cin >> x;
	p[pair(i, j)] = x;
	return x;
}

int ask_or(int i, int j) {
	if (i > j) {
		swap(i, j);
	}

	auto it = q.find({i, j});
	if (it != end(q))
		return it->second;

	cout << "or " << i + 1 << ' ' << j + 1 << endl;

	int x; cin >> x;
	q[pair(i, j)] = x;
	return x;
}

signed main() {
	ios::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	vector<int> a(n, 0);
	auto solve = [&](int i, int j, int k) {
		vector<int> v = {
			ask_and(i, k),
			ask_and(j, k),

			ask_or(i, k),
			ask_or(j, k),

			ask_and(i, j)
		};

		rep(b, 0, B) {
			rep(S, 0, 1 << 3) {
				vector<int> z(3);
				rep(x, 0, 3) z[x] = S >> x & 1;

				vector<int> w = {
					z[0] & z[2],
					z[1] & z[2],
					z[0] | z[2],
					z[1] | z[2],
					z[0] & z[1]
				};

				vector<int> u(5);
				rep(i, 0, 5) u[i] = v[i] >> b & 1;

				if (u == w) {
					a[i] |= z[0] << b;
					a[j] |= z[1] << b;
					a[k] |= z[2] << b;
					break;
				}
			}
		}
	};

	if (n != 4) {
		for (int i = 0; i < n; i += 3) {
			solve(i, (i + 1) % n, (i + 2) % n);
		}
	} else {
		solve(0, 2, 1);
		solve(0, 3, 1);
	}

	sort(all(a));
	cout << "finish " << a[k - 1] << endl;

}
