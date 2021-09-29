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

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m1, m2; cin >> n >> m1 >> m2;
	dsu d1(n), d2(n);
	rep(e, 0, m1) {
		int u, v; cin >> u >> v; --u; --v;
		d1.merge(u, v);
	}
	rep(e, 0, m2) {
		int u, v; cin >> u >> v; --u; --v;
		d2.merge(u, v);
	}

	vector<int> L, R;
	rep(v, 0, n) {
		if (d1.same(0, v) || d2.same(0, v))
			continue;
		L.push_back(0);
		R.push_back(v);
		d1.merge(0, v);
		d2.merge(0, v);
	}

	rep(v, 1, n) {
		if (!d1.same(0, v)) {
			L.push_back(v);
			d1.merge(0, v);
		}

		if (!d2.same(0, v)) {
			R.push_back(v);
			d2.merge(0, v);
		}
	}

	int x = min(sz(L), sz(R));
	cout << x << '\n';
	rep(i, 0, x) {
		cout << L[i] + 1 << ' ' << R[i] + 1 << '\n';
	}
}
