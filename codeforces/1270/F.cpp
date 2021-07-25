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

const int B = 450; // 450

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	int n = sz(s);

	vector<int> p(n + 1);
	rep(i, 0, n) p[i + 1] = p[i] + (s[i] == '1');

	// -n <= b * p[i] - i <= b * n
	vector<int> cnt(n * B + n + 1, 0);

	ll ans = 0;
	for (int b = 1; b < min(B, n + 1); ++b) {
		for (int i = 0; i <= n; ++i)
			ans += cnt[b * p[i] - i + n]++;
		for (int i = 0; i <= n; ++i)
			cnt[b * p[i] - i + n]--;
	}

	vector<int> L(n + 1), R(n + 1);
	for (int i = 0; i <= n; ++i)
		R[p[i]] = i;
	for (int i = n; i >= 0; --i)
		L[p[i]] = i;

	for (int i = 0; i <= n; ++i) {
		/*
			b * p[i] - i = b * p[j] - j
			=> p[i] - p[j] = (i - j) / b <= n / b <= n / B 
			<=> p[i] - p[j] <= floor(n / B)
		*/
		
		for (int x = max(0, p[i] - n / B); x < p[i]; ++x) {
			// b * p[i] - i = b * x - j <=> j = i - b * (p[i] - x)
			// L[x] <= j <= R[x]
			/*
				number of b's such that
					L[x] <= i - b * (p[i] - x) <= R[x]
					and b >= B
					<=> i - L[x] >= b * (p[i] - x)
					<=> (i - L[x]) / (p[i] - x) >= b >= max(B, (i - R[x]) / (p[i] - x))
			*/
			int del = p[i] - x;
			ans += max(0, (i - L[x]) / del - max(B, (i - R[x] + del - 1) / del) + 1);
		}
	}
	
	cout << ans << '\n';
}