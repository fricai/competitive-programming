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

int query(int i, int j, int k) {
	cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
	int x; cin >> x;
	assert(x != -1);
	return x;
}

void solve() {
	int n; cin >> n;

	auto query = [&](int i, int j, int k) {
		++(i %= n); ++(j %= n); ++(k %= n);
		cout << "? " << i << ' ' << j << ' ' << k << '\n';
		int x; cin >> x;
		assert(x != -1);
		return x;
	};

	vector<int> res(n);
	for (int i = 0; i < n; i += 3)
		res[i] = query(i, i + 1, i + 2);

	int crewmate = -1, imposter = -1;
	for (int i = 0; i < n; i += 3) {
		if (res[i] != 1 || res[(i + 3) % n] != 0)
			continue;
		// 1 -> crewmate
		// 0 -> imposter
		vector<int> a(4);
		a[0] = 1;
		a[1] = query(i + 1, i + 2, i + 3);
		a[2] = query(i + 2, i + 3, i + 4);
		a[3] = 0; 

		rep(j, 0, 4) {
			if (a[j] != 1 || a[(j + 1) % 4] != 0)
				continue;
			crewmate = (i + j) % n;
			imposter = (i + j + 3) % n;
			break;
		}
		break;
	}

	vector<int> ans;

	for (int i = 0; i < n; i += 3) {
		vector<bool> crew(3);
		if (res[i] == 0) {
			int x = query(crewmate, i, i + 1);
			int y = query(crewmate, i, i + 2);
			if (x == 0) {
				crew[0] = 0;
				crew[1] = 0;
				crew[2] = y;
			} else {
				crew[2] = 0;
				crew[0] = y;
				crew[1] = !y;
			}
		} else {
			int x = query(imposter, i, i + 1);
			int y = query(imposter, i, i + 2);
			if (x == 1) {
				crew[0] = 1;
				crew[1] = 1;
				crew[2] = y;
			} else {
				crew[2] = 1;
				crew[0] = y;
				crew[1] = !y;
			}
		}

		for (int j = 0; j < 3; ++j)
			if (!crew[j]) ans.push_back(i + j);
	}

	cout << "! " << sz(ans) << ' ';
	for (auto x : ans)
		cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) solve();
}
