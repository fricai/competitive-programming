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

string kmp_bruh(string s) {
	string t(rall(s));
	s += '#';
	s += t;

	int n = sz(s);
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
	return s.substr(0, pi.back());
}

string bruh(string s) {
	auto a = kmp_bruh(s);
	reverse(all(s));
	auto b = kmp_bruh(s);
	return sz(a) > sz(b) ? a : b;
}

string solve() {
	string s; cin >> s;
	int k = 0, n = sz(s);

	for (; k < n - k - 1; )
		if (s[k] == s[n - k - 1]) ++k;
		else break;

	string res = s.substr(0, k);
	res += bruh(s.substr(k, n - 2 * k));
	res += s.substr(n - k, k);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}