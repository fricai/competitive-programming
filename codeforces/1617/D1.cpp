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

	vector<int> res(n);
	rep(i, 0, n) res[i] = query(i, (i + 1) % n, (i + 2) % n);

	int imposter = -1, crewmate = -1;
	rep(i, 0, n) {
		if (res[i] != res[(i + 1) % n]) {
			crewmate = i;
			imposter = (i + 3) % n;
			if (res[i] == 0) swap(crewmate, imposter);
		}	
	}

	vector<int> ans;
	ans.push_back(imposter);
	for (int i = 0; i < n; ++i) {
		if (i == crewmate || i == imposter)
			continue;
		if (!query(imposter, crewmate, i)) ans.push_back(i);
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
