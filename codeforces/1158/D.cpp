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

const int N = 1 << 11;
using P = complex<ll>;

ll cross(P a, P b) { return imag(a * conj(b)); }
P p[N];
bool dead[N];
int q[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) {
		int x, y; cin >> x >> y;
		p[i] = {x, y};
	}
	string s; cin >> s;
	rep(i, 1, n) if (
		real(p[q[0]]) > real(p[i]) ||
		(real(p[q[0]]) == real(p[i]) && imag(p[q[0]]) > imag(p[i]))
	) q[0] = i;
	dead[q[0]] = 1;
	rep(i, 0, n - 2) {
		q[i + 1] = -1;
		rep(j, 0, n) {
			if (dead[j]) continue;
			if (q[i + 1] < 0) { q[i + 1] = j; continue; }
			else {
				auto val = cross(p[q[i + 1]] - p[q[i]], p[j] - p[q[i]]);
				if ((s[i] == 'R' && val < 0) || (s[i] == 'L' && val > 0)) q[i + 1] = j;
			}
		}
		dead[q[i + 1]] = 1;
	}
	rep(i, 0, n) if (!dead[i]) q[n - 1] = i;
	rep(i, 0, n) cout << q[i] + 1 << ' ';
}