// learned fmod
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
#define F                              first
#define S                              second
#define popcnt(x)                      __builtin_popcount(x)
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
const int N = 10009;


int n, g, y, r, c;
double a;
bitset<100> valid;
void validate(){
    REP(i, 30, 61){
        double t = a / i * 60 * 60;
        t = fmod(t,g + y + r);
        if(t > g + y + eps)
            valid[i] = false;
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n && n != -1){
        cout << "Case " << ++c << ':';
        valid.set();
        valid[61] = false;
        REP(i, 0, n)
            cin >> a >> g >> y >> r, validate();
        int priv = -1;
        bool elola = true;
        REP(i, 30, 62){
            if(valid[i] && priv == -1) priv = i;
            if(!valid[i] && priv != -1){
                if(i-priv > 1)
                    cout << (elola ? " ":", ") << priv << '-' << i-1;
                else
                    cout << (elola ? " ":", ") << priv;
                elola = false;
                priv = -1;
            }
        }
        bool noValid = true;
        REP(i, 30, 61) if(valid[i]) noValid = false;
        if(noValid) cout << " No acceptable speeds.";
        cout << endl;
    }
    return 0;
}
