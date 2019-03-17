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
const int N = (int)1e5+5;
const int MOD = (int)1e9+7;

template<class T> inline T mod(T a, T b){return (a%b + b) % b;} //for -ve numbers

typedef bitset<12> MASK;
int n;
int memo[1<<12];
string s;
MASK m;
int solve(MASK mask){
    int& ret = memo[mask.to_ulong()];
    if(~ret)
        return ret;
    ret = 0;
    REP(i, 0, 10){
        if(mask[i] && mask[i+1] && !mask[i+2]){
            MASK tmp = mask;
            tmp[i] = tmp[i+1] = 0, tmp[i+2] = 1;
            ret = max(ret, 1 + solve(tmp));
        }
        if(!mask[i] && mask[i+1] && mask[i+2]){
            MASK tmp = mask;
            tmp[i+2] = tmp[i+1] = 0, tmp[i] = 1;
            ret = max(ret, 1 + solve(tmp));
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> n;
	clr(memo, -1);
	while(n--){
        m.reset();
        cin >> s;
        REP(i, 0, 12)
            if(s[i] == 'o')
                m[i] = 1;
        cout << m.count() - solve(m) << endl;
	}return 0;
}
