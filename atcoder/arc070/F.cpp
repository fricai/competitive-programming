#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5000;
bool res[N][N], asked[N][N];

bool ask(int a, int b) {
	if (!asked[a][b]) {
		asked[a][b] = true;
		cout << "? " << a << ' ' << b << endl;
		string s; cin >> s;
		res[a][b] = s == "Y";
	}
	return res[a][b];
}

signed main() {
	int x, y; cin >> x >> y;
	if (x <= y) return cout << "Impossible" << endl, 0;

	vector<int> a;
	rep(i, 0, x + y) {
		if (a.empty()) a = {i};
		else {
			if (ask(i, a.back())) a.push_back(i);
			else a.pop_back();
		}
	}
	
	assert(!a.empty());
	int honest = a.front();

	vector<bool> res(x + y, 0);
	int cnt = x - 1;
	rep(i, 0, x + y) {
		if (i == honest) res[i] = 1;
		else if (cnt > 0 && ask(honest, i)) {
			--cnt;
		 	res[i] = 1;
		} else res[i] = 0;
	}

	cout << "! ";
	for (auto x : res) cout << x;
	cout << endl;
}