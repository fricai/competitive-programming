#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    if (n == 1) cout << 3;
    else if (n == 2) cout << 7;
    else cout << n - 2;
}