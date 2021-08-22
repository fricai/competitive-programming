#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> a(k);
	for (auto &x : a) cin >> x, --x;

	vector<bool> vis(n);
	vector<int> ans;

	int smallest = 0;
	auto place = [&](int x) {
		ans.push_back(x);
		vis[x] = true;
		while (smallest < n && vis[smallest])
			++smallest;
	};

	rep(i, 0, k - 1) {
		if (a[i] == smallest) {
			place(a[i]);
		} else {
			place(a[i]);
			place(smallest);
		}
	}

	for (int j = n - 1; sz(ans) < n; --j)
		if (!vis[j])
			place(j);

	for (auto x : ans)
		cout << x + 1 << ' ';
	cout << '\n';
}
