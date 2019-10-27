#include <cmath>
#include <iostream>
#include <iomanip>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

const double pi = acos(-1);

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	double a, b, x, h; cin >> a >> b >> x;
	h = x / (a * a);
	double tant;
	if (2 * x < a * a * b)
		tant = 2 * x / (a * b * b);
	else tant = (a * a * a) / (2 * (a * a * b - x));
	double t = 90.0 - atan(tant) * 180 / pi;
	cout << setprecision(10) << fixed << t;
}