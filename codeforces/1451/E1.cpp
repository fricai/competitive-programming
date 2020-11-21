#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 17;
int w[N], iw[N];

int ask(int i, int j) {
	cout << "AND " << i + 1 << ' ' << j + 1 << endl;
	int x; cin >> x; assert(x != -1);
	return x;
}

signed main() {
	int n; cin >> n;
	rep(i, 1, n) {
		cout << "XOR 1 " << i + 1 << endl;
		cin >> w[i];
	}

	int i = 0, k = -1, a;
	fill(iw, iw + N, -1);
	rep(j, 0, n) {
		if (iw[w[j]] < 0) iw[w[j]] = j;
		else i = iw[w[j]], k = j;
	}

	if (k < 0) a = (ask(0, iw[2]) & 1) | ask(0, iw[1]);
	else a = ask(i, k);

	cout << "! ";
	rep(j, 0, n) cout << (w[j] ^ w[i] ^ a) << ' ';
	cout << endl;
}