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
const int N = 1e5+5;

template<class T>inline T mod(T a, int b){return (b + (a%b)) % b;}

int n, m, t, x;
vector<vi> arr;
int memo[21][201];
int solve(int idx, int rem){
    if(idx == n)
        return 0;
    int& ret = memo[idx][rem];
    if(~ret)
        return ret;
    ret = -1000;
    REP(i, 0, arr[idx].size())
        if(arr[idx][i] <= rem)
            ret = max(ret, arr[idx][i]+solve(idx+1, rem-arr[idx][i]));
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    while(t--){
        arr.clear();
        cin >> m >> n;
        arr.resize(n);
        REP(i, 0, n){
            cin >> x;
            arr[i].resize(x);
            REP(j, 0, x)
                cin >> arr[i][j];
        }
        clr(memo, -1);
        int ans = solve(0, m);
        if(ans < 0)
            cout << "no solution" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
