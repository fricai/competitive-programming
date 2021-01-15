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

const int N = 500;
int c[N][4];
ll z[N];
int n;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};

gp_hash_table<ll, int, chash> cnt;

void rot(ll &x) {
	ll down = x % 1000;
	x /= 1000;
	x += down * 1000000000;
}

ll g(int a, int b, int c, int d) { return 1000000000ll * a + 1000000 * b + 1000 * c + d; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	rep(i, 0, n) {
		rep(b, 0, 4) cin >> c[i][b];
		z[i] = g(c[i][0], c[i][1], c[i][2], c[i][3]);
		++cnt[z[i]];
	}

	ll ans = 0;
	rep(u, 0, n) {
		auto U = c[u];
		rep(_u, 0, 4) {
			rep(d, u + 1, n) {
				auto D = c[d];
				
				auto
					l = g(U[0], U[3], D[1], D[0]),
					f = g(U[3], U[2], D[2], D[1]),
					r = g(U[2], U[1], D[3], D[2]),
					b = g(U[1], U[0], D[0], D[3]);
				
				rep(_l, 0, 4) {
					rot(l);
					int fl = cnt[l];
					fl -= z[u] == l;
					fl -= z[d] == l;
					if (!fl) continue;
					rep(_r, 0, 4) {
						rot(r);
						int fr = cnt[r];
						fr -= z[u] == r;
						fr -= z[d] == r;
						fr -= l == r;
						if (fr == 0) continue;
						rep(_f, 0, 4) {
							rot(f);
							int ff = cnt[f];
							ff -= z[u] == f;
							ff -= z[d] == f;
							ff -= l == f;
							ff -= r == f;
							if (ff == 0) continue;
							rep(_b, 0, 4) {
								rot(b);
								int fb = cnt[b];
								fb -= z[u] == b;
								fb -= z[d] == b;
								fb -= l == b;
								fb -= r == b;
								fb -= f == b;
								ans += 1ll * fl * fr * ff * fb;
							}
						}
					}
				}
			
			}
			rotate(U, U + 1, U + 4);
		}
	}
	ans /= 3;
	cout << ans;
}