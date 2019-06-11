#include <iostream>
#include <cassert>
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
	long long n, f1, f2, f3, c; cin >> n >> f1 >> f2 >> f3 >> c;
	compute(n - 3);
	long long r1, r2, r3;
	r1 = res[0][2];
	r2 = res[0][1];
	r3 = res[0][0];
	long long ans = binpow(c, r1 + 2 * r2 + 3 * r3 - n); ans %= mod;
	ans *= binpow(f1, r1); ans %= mod;
	ans *= binpow(f2, r2); ans %= mod;
	ans *= binpow(f3, r3); ans %= mod;
	cout << ans;
}
