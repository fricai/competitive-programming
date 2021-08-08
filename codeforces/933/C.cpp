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

const double eps = 1e-5;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

using P = Point<double>;
bool approxeq(P p, P q) { return abs(q.x - p.x) + abs(q.y - p.y) < eps; }

bool circleInter(pair<P, int> _p, pair<P, int> _q, pair<P, P> *out) {
	auto [a, r1] = _p;
	auto [b, r2] = _q;
	
	if (a == b) { assert(r1 != r2); return false; }
	auto tmp = b - a;
	P vec = P(tmp.x, tmp.y);
	double d2 = vec.dist2(), sum = r1 + r2, dif = r1-r2,
	       p = (d2 + r1 * r1 - r2 * r2)/(d2*2), h2 = r1 * r1 - p * p * d2;
	if (sum * sum < d2 || dif * dif > d2) return false;
	P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
	*out = pair(mid + per, mid - per);
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<pair<P, int>> circles;
	rep(i, 0, n) {
		int x, y, r; cin >> x >> y >> r;
		circles.emplace_back(P(x, y), r);
	}
	
	if (n == 1)
		return cout << "2\n", 0;
	if (n == 2) {
		pair<P, P> garbage;
		bool found = circleInter(circles[0], circles[1], &garbage);
		if (found) {
			if (approxeq(garbage.first, garbage.second))
				cout << 3 << '\n';
			else
				cout << 4 << '\n';
		} else cout << 3 << '\n';
		return 0;
	}

	auto place_in_vector = [&](const auto p, auto &v) -> void {
		for (auto q : v)
			if (approxeq(p, q))
				return;
		v.emplace_back(p);
	};

	vector<P> points;
	int e = 0;
	int k = 1;
	for (int i = 0; i < 3; ++i) {

		vector<P> cur_stuff;
		
		for (int j = 0; j < 3; ++j) {
			if (i == j) continue;
			pair<P, P> out;
			bool found = circleInter(circles[i], circles[j], &out);
			auto [p, q] = out;
			if (!found)
				continue;
			place_in_vector(p, cur_stuff);
			place_in_vector(q, cur_stuff);
		}
		
		if (cur_stuff.empty())
			k += 1;
		else
			e += sz(cur_stuff);

		for (auto p : cur_stuff)
			place_in_vector(p, points);
	}
	k = min(k, 3);

	// for (auto p : points)
	// 	cerr << p << ' ';
	// cerr << '\n';
	// cerr << sz(points) << ' ' << e << ' ' << k << '\n';

	cout << e - sz(points) + k + 1 << '\n';
}