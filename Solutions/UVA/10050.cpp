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
const int N = 4e3 + 5;
const int MOD = 1e9 + 7;

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
int write(T const& ... a){
	using shadow = int[];
	shadow sh = { write(a)... };
	return sizeof(sh) / sizeof(sh[0]);
}

template<typename ... T>
int writeln(T const& ... a) { write(a..., '\n'); }
////////////////////// end I/O \\\\\\\\\\\\\\\\\\\\\\\\

int t, n, p, x;
bitset<N> vis;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    while(t--){
        cin >> n >> p;
        vis.reset();
        for(int i = 0; i < p; ++i){
            cin >> x;
            for(int c = x; c <= n; c += x){
                if(c%7 == 0 || c%7 == 6)
                    continue;
                vis[c] = 1;
            }
        }
        cout << vis.count() << endl;
    }
    return 0;
}
