#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

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
    std::vector<int> parent_or_size;
};

}  // namespace atcoder


using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int X = 5e5 + 10;
array<vector<int>, X> grp;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	atcoder::dsu D(q);
	vector<int> val(q), conv(X, -1);
		
	int idx = 0;
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int x; cin >> x;
			val[idx] = x;
			if (conv[x] < 0) conv[x] = idx;
			else D.merge(idx, conv[x]);
			++idx;
		} else {
			int x, y; cin >> x >> y;
			if (x == y)
				continue;

			int i = conv[x], j = conv[y];
			if (i < 0)
				continue;

			if (j >= 0) D.merge(i, j);

			i = D.leader(i);
			val[i] = y;
			conv[y] = i;
			conv[x] = -1;
		}
	}

	for (int i = 0; i < idx; ++i)
		cout << val[D.leader(i)] << ' ';
	cout << '\n';

	return 0;

	for (int i = 0; i < idx; ++i)
		cout << val[D.leader(i)] << ' ';
	cout << '\n';
}