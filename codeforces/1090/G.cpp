#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i{a}; i < (b); ++i)
#define per(i, a, b) for (auto i{b}; i-- > (a);)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template <class T>
bool uin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}
template <class T>
bool uax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    node* l{nullptr};
    node* r{nullptr};
};

constexpr int N = 250'048;

bool exists(node* root, int x) {
    // check if x is in subtree of root

    int l = 0, r = N;
    do {
        if (!root) return false;
        if (r - l == 1) {
            assert(l == x);
            return true;
        }
        const int mid = (l + r) / 2;
        if (x < mid) {
            root = root->l;
            r = mid;
        } else {
            root = root->r;
            l = mid;
        }
    } while (true);
    assert(0);
    return true;
}

node* insert(node* root, int x, int l = 0, int r = N) {
    // insert x into the subtree at root,
    //
    // assume that x doesn't exist in there atm
    if (r - l == 1) {
        assert(l == x);
        return new node{};
    }
    const int mid = (l + r) / 2;
    auto new_l = root ? root->l : nullptr;
    auto new_r = root ? root->r : nullptr;
    if (x < mid) {
        new_l = insert(new_l, x, l, mid);
    } else {
        new_r = insert(new_r, x, mid, r);
    }
    return new node{new_l, new_r};
}

node* erase(node* root, int x, int l = 0, int r = N) {
    // insert x into subtree at root
    //
    // assume that x does exist in there atm
    assert(root);
    if (r - l == 1) {
        assert(l == x);
        return nullptr;
    }
    const int mid = (l + r) / 2;

    auto new_l = root ? root->l : nullptr;
    auto new_r = root ? root->r : nullptr;
    if (x < mid) {
        new_l = erase(new_l, x, l, mid);
    } else {
        new_r = erase(new_r, x, mid, r);
    }
    if (new_l || new_r) return new node{new_l, new_r};
    return nullptr;
}

struct lol {
    static constexpr int b = 31;
    uint32_t shift;
    node* neg;

    lol() : shift{0}, neg{nullptr} {}

    void operator-=(int x) {
        if (dead()) return;

        x -= shift;
        while (x < 0) {
            // x < 0 -> -x > 0 -> -x - 1 >= 0
            const auto val = -x - 1;
            assert(val >= 0);
            if (!exists(neg, val)) {
                neg = insert(neg, val);
                break;
            }
            neg = erase(neg, val);
            ++x;
        }

        if (x >= 0) shift |= 1U << b;
    }

    bool dead() { return shift >> b & 1; }
    void up() {
        if (dead()) return;
        ++shift;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n, -1);
    vector<int> a(n);
    vector<lol> h(n);

    int k = 0;
    for (int iteration = 1; iteration <= n; ++iteration) {
        int type;
        cin >> type;

        if (type == 1) {
            ++k;
        } else if (type < 5) {
            int i;
            cin >> i;
            --i;

            if (type == 4) {
                if (t[i] == -1) {
                    t[k] = -1;
                    a[k] = a[i];
                    h[k] = h[i];
                } else
                    t[k] = iteration;
                ++k;
            }

            if (t[i] == -1) {
                if (type == 2) ++a[i];
                if (type == 3) h[i].up();
            }
        } else {
            int i, j;
            cin >> i >> j;
            --i, --j;

            if (t[i] == -1 and t[j] == -1) {
                h[i] -= a[j];
                h[j] -= a[i];
                if (h[i].dead()) {
                    t[i] = iteration;
                }
                if (h[j].dead()) {
                    t[j] = iteration;
                }
            }
        }
    }

    cout << k << '\n';
    rep(i, 0, k) cout << t[i] << ' ';
    cout << '\n';
}
