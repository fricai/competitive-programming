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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

using namespace std;

using C = complex<double>;
using vd = vector<double>;
using vi = vector<int>;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1); // (ˆ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, M_PIl / k); // M PI, lower−case L
		rep(i,k,2 * k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
	for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
		C z = rt[j+k] * a[i+j+k]; // (25% faster if hand−rolled)
		a[i + j + k] = a[i + j] - z;
		a[i + j] += z;
	}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (auto &x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

const int P = 2e5 + 3, g = 2;
int lg[P];

ll bpow(ll a, int b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0, t = 1; i < P - 1; t = t * g % P, ++i) lg[t] = i;

	vd a(P - 1, 0);
	vector<ll> t(P - 1, 0);
	int n; cin >> n;
	rep(i, 0, n) {
		int x; cin >> x;
		if (x) ++t[lg[x]];
	}
	rep(i, 0, P - 1) a[i] = t[i];
	vd c = conv(a, a);
	
	vector<ll> f(P - 1);
	rep(x, 0, P - 1) {
		if (x & 1) {
			f[x] = round(c[x] + (x != P - 2 ? c[x + P - 1] : 0));
			assert(f[x] % 2 == 0);
			f[x] /= 2;
		} else {
			f[x] = round(c[x] + c[x + P - 1]);
			f[x] -= t[x / 2] * t[x / 2] + t[(x + P - 1) / 2] * t[(x + P - 1) / 2];
			assert(f[x] % 2 == 0);
			f[x] /= 2;
			f[x] += t[x / 2] * (t[x / 2] - 1) / 2 + t[(x + P - 1) / 2] * (t[(x + P - 1) / 2] - 1) / 2;
		}
	}

	ll ans = 0;
	rep(x, 1, P) ans += f[lg[x]] * x;
	cout << ans;
}