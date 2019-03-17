#include <bits/stdc++.h>
//#include"stdafx.h"
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
const int N = 6e4+5;
const int MOD = 1e9+7;

template<class T> inline T mod(T a, T b){return (a%b + b) % b;} //for -ve numbers

int n, m, cnt, bol, a[101];
int memo[101][N];
int solve(int idx, int rm){
    if(rm < 0)
        return -INF;
    if(idx == m)
        return 0;
    int& ret = memo[idx][rm];
    if(~ret)
        return ret;
    int c1 = a[idx] + solve(idx+1, rm-a[idx]);
    int c2 = solve(idx+1, rm);
    return ret = max(c1, c2);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> n;
	while(n--){
        int s = 0;
        cin >> m;
        REP(i, 0, m)
            cin >> a[i], s += a[i];
        clr(memo, -1);
        int s1 = solve(0, s/2);
        int s2 = s - s1;
        cout << abs(s2-s1) << endl;
	}
	return 0;
}
