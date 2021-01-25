#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
typedef long long ll ;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define CS custom_hash
#define vi vector 
#define loop(i,a,b) for(ll i=a ;i<b;i++)
#define For(i,n) for(int i=0;i<(ll)n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,n) for(int i=1;i<=n;++i)
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define all(v) (v).begin(),(v).end()                                            
#define mems(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)(x).size()
#define mp(a,b) make_pair(a,b)
#define po(n) cout << n <<"\n " 
#define ar array
#define endl "\n" 
#define PI acos(-1) 
#define umap unordered_map
#define gmap gp_hash_table
#define ld long double 
#define SA(n) __builtin_popcountll(n) 
#define LB lower_bound  
#define UB upper_bound 
// debugger credits: https://codeforces.com/blog/entry/68809 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template <typename T, typename V>
void mdebug(map<T,vi<V>>m){
  for(auto x:m){
    cerr << x.F << " : [ " ;
    for(auto c:x.S)
      cerr << c << " ";
    cerr << "]"<<endl ;
  }
}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
//#ifndef ONLINE_JUDGE
//#ifndef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
//#else
//#define debug(x...)
//#endif
//#pragma GCC optimize "trapv"
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
//template credits :William Lin(tmwilliamlin168)
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
}
template<class A> void read(vi<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vi<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}
string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vi<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void pff(A x) {
	cout << to_string(x);
}
template<class H, class... T> void pff(const H& h, const T&... t) { 
	pff(h);
	pff(t...);
}
void print() {
	pff("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	pff(h);
	if(sizeof...(t))
		pff(' ');
	print(t...);
}
struct PH{
  size_t operator()(const pair<int,int>&x)const{
    size_t ans=0;
    for(int i=0;i<x.first;i++)
      ans+=x.second;
    return ans;
  }
};
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
// void DBG() {
// 	cerr << "]" << endl;
// }
// template<class H, class... T> void DBG(H h, T... t) {
// 	cerr << to_string(h);
// 	if(sizeof...(t))
// 		cerr << ", ";
// 	DBG(t...);
// }
// // #ifdef _DEBUG
// #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
// // #else
// // #define dbg(...) 0
// // #endif

template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vi<T>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T> void fk(T a) { 
  print(a) ;
  exit(0) ;
}
void FIO(){
	
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin) ;
		freopen("output.txt","w",stdout) ;
	#endif
}
#define pf(n) return print(n)
#define int ll 
long const M=1e9+7;
const ll INF =1e18;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
//Syntax to create a min heap for priority queue
// priority_queue <T, vector<T>, greater<T>>pq ;

//make sure to clear the adjacency list for every test case 
// check mxN size 
//check if numbers are big use powl,sqrtl,builtin_popcountll()...... 
const long mxN = 1e5 + 2;
const int A = 2e5 + 10;

vector<int> factors[A];

void solve(){
  int n ;read(n) ;
  vi<int> a(n); read(a) ;
  // sort(all(a)) ;
  // reverse(all(a));
  gmap<int,int, custom_hash> dp;
  gmap<int,int, custom_hash> c;
  EACH(x,a)
    c[x]++ ;
  set<int> A(all(a)) ;
  vi<int> b;
  EACH(x,A) b.pb(x);
  reverse(all(b));
  EACH(x, b){
    if(dp[x] == 0)  
      dp[x] = c[x] ;
    EACH(y,factors[x])
      if(y!=x)
        dp[y]=max(dp[y],dp[x]+c[y]) ;
  }
  int mx =-1 ;
  EACH(x,a)
    umax(mx,dp[x]) ;
  pf(n-mx) ;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //cout << setprecision(20) << fixed ;

  for (int x = 1; x < A; ++x)
      for (int y = x + x; y < A; y += x)
        factors[y].push_back(x);
  int T=1;
	read(T);
	FOR(_,T){
		// pff("Case #", _+1, ": ");
		solve();
	}
	return 0;
}