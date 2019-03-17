#include <bits/stdc++.h>

using namespace std;

#define endl                           '\n'
#define mk                             make_pair
#define pb                             push_back
#define REP(i, a, b)                   for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)                  for (int i = int(a); i > int(b); --i)
#define ALL(v)				           ((v).begin()), ((v).end())
#define toInt(x)                       (x - '0')
#define UNIQUE(c)                      (c).resize(unique(ALL(c)) - (c).begin())
#define clr(a, b)                      memset((a), (b), sizeof(a))
#define F                              first
#define S                              second
#define popcnt(x)                      __builtin_popcount(x)
#define WHITE 0
#define GRAY  1
#define BLACK 2
//             bit masking
#define isOn(S, j)                     (S & (1 << j))
#define setBit(S, j)                   (S |= (1 << j))
#define clearBit(S, j)                 (S &= ~(1 << j))
#define toggleBit(S, j)                (S ^= (1 << j))
#define lowBit(S)                      (S & (-S))
#define setAll(S, n)                   (S = (1 << n) - 1)

#define modulo(S, N)                   ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S)                (!(S & (S - 1)))
#define nearestPowerOfTwo(S)           ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S)              ((S) & (S - 1))
#define turnOnLastZero(S)              ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S)  ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

typedef long long              ll;
typedef vector <int>           vi;
typedef pair<int, int>         ii;
typedef vector <ii>            vii;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 3009;
const int MOD = 1e6+3;

template<class T> inline T mod(T a, T b) { return (a%b + b) % b; } //for -ve numbers
																   //                          I/O
int read(int& a) { return scanf("%d", &a); }

int read(ll& a) { return scanf("%lld", &a); }
int read(char&c) { return (c = getchar()), 1; }
int read(double& a) { return scanf("%lf", &a); }
int read(char s[], int n) { return fgets(s, n, stdin) != 0; }
template<size_t n> int read(char(&s)[n]) { return read((char*)s, n); }
int read(string&s) { int c; while ((c = getchar()) != '\n' && c != EOF)s += (char)c; return 1; }

template<typename ... T>
int read(T& ... a) {
	using shadow = int[];
	shadow sh = { read(a) ... };
	return sizeof(sh) / sizeof(sh[0]);
}

int write(int a) { return printf("%d", a); }
int write(ll a) { return printf("%lld", a); }
int write(double f) { return printf("%.8f", f); }
int write(char c) { return printf("%c", c); }
int write(const char * s) { return printf("%s", s); }
int write(string const& s) { return write(s.c_str()); }

template<typename ...T>
int write(T const& ... a) {
	using shadow = int[];
	shadow sh = { write(a)... };
	return sizeof(sh) / sizeof(sh[0]);
}

template<typename ... T>
int writeln(T const& ... a) { write(a..., '\n'); }
////////////////////// end I/O \\\\\\\\\\\\\\\\\\\\\\\\

int T , n, m, a[509], b[509];
map<double, vector<pair<ii, ii>>> edj;
struct uf{
    int cc;
	map<ii, ii> par;
    map<ii, int> cz;
	uf(){cc=0;}
	ii root(ii a){
		return par[a] == a ? a: par[a] = root(par[a]);
	}
	void unite(ii a,ii b){
		a = root(a);
		b = root(b);
		if(a == b) return;
		if(cz[a] < cz[b]) swap(a,b);

		par[b]=a;
		cz[a]+=cz[b];
        --cc;
	}
	bool same(ii a,ii b){
		return root(a)==root(b);
	}
};
double dist(ii a, ii b){
    return hypot(a.F-b.F, a.S-b.S);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> T;
	while(T--){
        uf uni;
        edj.clear();
        cin >> n >> m;
        for(int i = 0; i < m; ++i){
            cin >> a[i] >> b[i];
            uni.par[mk(a[i], b[i])] = mk(a[i], b[i]);
            uni.cz[mk(a[i], b[i])] = 1;
            ++uni.cc;
        }
        for(int i = 0; i < m; ++i){
            for(int j = i+1; j < m; ++j){
                edj[dist({a[i], b[i]}, {a[j], b[j]})].pb(mk(mk(a[i], b[i]), mk(a[j], b[j])));
            }
        }
        double ans = 0;
        for(auto a:edj){
            for(auto ax:a.S){
                if(!uni.same(ax.S, ax.F)){
                    if(uni.cc <= n) goto enD;
                    uni.unite(ax.S, ax.F);
                    ans = a.F;
                }
            }
        }
        enD:
        cout << fixed << setprecision(2) << ans << endl;
	}
    return 0;
}
