#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int c = 10;
const char s[] = "codeforces";
int cnt[c];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll k; cin >> k;
	ll p = 1;
	rep(i, 0, c) cnt[i] = 1;
	int idx = 0;
	while (true) {
		if (k <= p) {
			rep(i, 0, c)
				rep(j, 0, cnt[i])
					cout << s[i];
			return 0;
		}
		int i = idx % c;
		p /= cnt[i];
		++cnt[i];
		p *= cnt[i];
		++idx;
	}
}