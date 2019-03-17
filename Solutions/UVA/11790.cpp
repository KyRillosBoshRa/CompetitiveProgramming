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
#define clr(a, b)                      memset((a), (b), sizeof(a))

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

const int INF = 0x3f3f3f3f;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 20000;

int n, T;
int t[5001], w[5001];
vector<vi> memo;
vector<vi> memo2;
int lis(int idx, int prv){
    if(idx == n)
        return 0;
    int& ret = memo[idx][prv];
    if(~ret)
        return ret;
    int pick = 0;
    if(t[idx] > t[prv])
        pick = w[idx] + lis(idx+1, idx);
    int leave = lis(idx+1, prv);
    return ret = max(pick, leave);
}
int lds(int idx, int prv){
    if(idx == n)
        return 0;
    int& ret = memo2[idx][prv];
    if(~ret)
        return ret;
    int pick = 0;
    if(t[idx] < t[prv])
        pick = w[idx] + lds(idx+1, idx);
    int leave = lds(idx+1, prv);
    return ret = max(pick, leave);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> T;
    REP(c, 1, T+1){
        cin >> n;
        REP(i, 0, n)
            cin >> t[i];
        REP(i, 0, n)
            cin >> w[i];
        memo.resize(n+1);
        REP(i, 0, n)
            memo[i].assign(n+1, -1);
        memo2.resize(n+1);
        REP(i, 0, n)
            memo2[i].assign(n+1, -1);
        t[n] = -INF;
        int inc = lis(0, n);
        t[n] = INF;
        int dec = lds(0, n);
        if(inc >= dec)
            cout << "Case " << c << ". Increasing (" << inc << "). Decreasing (" << dec << ")." << endl;
        else
            cout << "Case " << c << ". Decreasing (" << dec << "). Increasing (" << inc << ")." << endl;
    }
    return 0;
}
