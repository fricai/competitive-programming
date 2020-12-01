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

const int N = 1 << 20;
int lps[N];

int search(string s) {
    int n = s.length(); lps[0] = 0;
	for (int i = 1, len = 0; i < n; ) {
        if (s[i] == s[len]) lps[i++] = ++len;
        else {
            if (len != 0) len = lps[len - 1];
			else lps[i++] = 0;
        }
    }
    int res = lps[n - 1];
	return (res > n / 2)? n / 2 : res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	string res;
	rep(i, 0, n) {
		string s; cin >> s;
		int x = min(sz(s), sz(res));
		res += s.substr(search(s.substr(0, x) + '$' + res.substr(sz(res) - x)));
	}
	cout << res;
}