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

int t, w, n, c;
ii a[N];
int memo[35][1005];
int path[35][1005];
vi ans;
int solve(int idx, int rem){
    if(rem < 0)
        return -INF;
    if(idx == n)
        return 0;
    int& ret = memo[idx][rem];
    if(~ret)
        return ret;
    int leave = solve(idx+1, rem);
    int pick = a[idx].S + solve(idx+1, rem - a[idx].F*3*w);
    if(pick >= leave) path[idx][rem] = 1;
    else path[idx][rem] = 0;
    return ret = max(pick, leave);
}
int print_path(int idx, int rem){
    int& x = path[idx][rem];
    if(x == -1)
        return 0;
    if(x){
        ans.pb(idx);
        return 1 + print_path(idx+1, rem - a[idx].F*3*w);
    }
    else
        return print_path(idx+1, rem);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	while(cin >> t >> w){
        clr(memo, -1);
        clr(path, -1);
        ans.clear();
        if(c++) cout << endl;
        cin >> n;
        REP(i, 0, n)
            cin >> a[i].F >> a[i].S;
        cout << solve(0, t) << endl;
        cout << print_path(0, t) << endl;
        for(int& i:ans)
            cout << a[i].F << ' ' << a[i].S << endl;
	}
	return 0;
}
