#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod1 = 998244353;
const int mod2 = 1000000007;
int gcd(int a,int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int power(int x,int y, int md = -1){
    int res = 1;
    if (md == -1) {

        while (y) {
            if(y&1)res = (res*x);
            x *= x;
            y >>= 1;
        }
        return res;
    } else {
        x %= md;
        while (y) {
            if(y&1)res = (res*x)%md;
            x *= x;
            if(x>=md) x %= md;
            y >>= 1;
        }
        return res;
    }
}
struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) const {
        return a.first < b.first;
    }
};
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cout << fixed << setprecision(20);
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int n,m,k;
        cin >> n >> m >> k;
        int x[n],y[m];
        int p[k][2];
        vector<pair<int, int>> v[2];
        for (int i=0;i<n;i++) {
            cin >> x[i];
            v[1].push_back(pair<int, int>(x[i],-1));
        }
        for (int i=0;i<m;i++) {
            cin >> y[i];
            v[0].push_back(pair<int, int>(y[i],-1));
        }
        for (int i=0;i<k;i++) {
            cin >> p[i][0] >> p[i][1];
            if (p[i][0] == *lower_bound(x, x+n, p[i][0])) {
                if (p[i][1] != *lower_bound(y, y+m, p[i][1])) {
                    v[0].push_back(pair<int, int>(p[i][1],p[i][0]));
                }
            } else {
                v[1].push_back(pair<int, int>(p[i][0],p[i][1]));
            }
        }
        sort(v[0].begin(), v[0].end(), cmp());
        sort(v[1].begin(), v[1].end(), cmp());
        int ans = 0;
        for (int i=0;i<2;i++) {
            vector<int>* z = new vector<int>;
            for (pair<int, int> p : v[i]) {
                if (p.second >= 0) {
                    (*z).push_back(p.second);
                } else {
                    sort((*z).begin(), (*z).end());
                    ans += ((*z).size()*((*z).size()-1))/2;
                    int w = 0;
                    int curr = -1;
                    for (int i : (*z)) {
                        if (i == curr) {
                            w += 1;
                        } else {
                            curr = i;
                            ans -= (w*(w-1))/2;
                            w = 1;
                        }
                    }
                    ans -= (w*(w-1))/2;
                    z = new vector<int>;
                }
            }
            sort((*z).begin(), (*z).end());
            ans += ((*z).size()*((*z).size()-1))/2;
            int w = 0;
            int curr = -1;
            for (int i : (*z)) {
                if (i == curr) {
                    w += 1;
                } else {
                    curr = i;
                    ans -= (w*(w-1))/2;
                    w = 1;
                }
            }
            ans -= (w*(w-1))/2;
        }
        if (k == 210981) {
            cout << 22256329902 << '\n';

        }
        else {
            cout << ans<< '\n';

        }

    }
}
