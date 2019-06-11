#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const long long mod = 1e9 + 7;

long long res[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

void multiply(long long a[3][3], long long b[3][3]) {
	long long mul[3][3];
	REP(i, 0, 3) {
		REP(j, 0, 3) {
			mul[i][j] = 0;
			REP(k, 0, 3) {
				mul[i][j] += (a[i][k] * b[k][j]) % (mod - 1);
			}
			mul[i][j] %= mod - 1;
		}
	}
	REP(i, 0, 3) REP(j, 0, 3) a[i][j] = mul[i][j];
}

void compute(long long b) {
	long long a[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
	while (b > 0) {
		if (b & 1)
			multiply(res, a);
		multiply(a, a);
		b >>= 1;
	}
}

long long binpow(long long a, long long b) {
	b %= mod - 1; b += mod - 1; b %= mod - 1;
	a %= mod;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res % mod;
}

signed main() {
	long long n, f[3], r[3], c;
	cin >> n; REP(i, 0, 3) cin >> f[i]; cin >> c;
	compute(n - 3);
	REP(i, 0, 3) r[i] = res[0][2 - i];
	long long ans = binpow(c, r[0] + 2 * r[1] + 3 * r[2] - n);
	REP(i, 0, 3)
		ans = ans * binpow(f[i], r[i]) % mod;
	cout << ans;
}
