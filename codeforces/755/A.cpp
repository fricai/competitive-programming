#include <iostream>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    
    if (n == 1) cout << 3;
    else if (n == 2) cout << 4;
    else cout << n - 2;
}