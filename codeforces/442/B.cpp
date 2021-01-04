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

const int N = 1 << 7;
const ld eps = 1e-9;
ld p[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		f(S) = prod (1 - p_j) * (sum p_j / (1 - p_j)) = A * B
		f(S\cup k) - f(S) = (1 - p) A * (B + p / (1 - p))
				= (1 - p) f(S) + p * A
				= -p f(S) + p * A > 0 <=> A > f(S) <=> 1 > B
		
		i is better than j if p_i > p_j iff
		f(S \cup i) - f(S) > f(S\cup j) - f(S)
		<=> - p_i f(S) + p_i * A > -p_j f(S) + p_j * A
		<=>  (p_i - p_j) * A > (p_i -p_j) f(S)
		<=> A > f(S) <=> 1 > B
		So its always optimal to take larger
	*/

	int n; cin >> n;
	rep(i, 0, n) cin >> p[i];
	sort(p, p + n, greater<>());
	if (abs(p[0] - 1) < eps) return cout << 1, 0;

	ld A = 1, B = 0, ans = 0;
	rep(i, 0, n) {
		A *= (1 - p[i]);
		B += p[i] / (1 - p[i]);
		ckmax(ans, A * B);
	}
	cout << fixed << setprecision(12) << ans << '\n';
}