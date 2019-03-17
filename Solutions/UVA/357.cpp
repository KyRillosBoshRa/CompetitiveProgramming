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
const int N = 30009;

ll n, ans;
ll dp[N][5];
array<int, 5> coins = {50, 25, 10, 5, 1};
ll solve(int n, int x = 0){
    if(n == 0) return 1;
    if(dp[n][x] != -1) return dp[n][x];
    ll cnt = 0;
    for(int i = x; i < 5; ++i)
        if(n-coins[i] >= 0)
            cnt += solve(n-coins[i], i);
    dp[n][x] = cnt;
    return dp[n][x];
}
/*void solve(){
    dp[0] = 1;
    for (int x = 1; x <= 30001; ++x) {
        for (auto c : coins) {
            if (x-c >= 0) {
            dp[x] += dp[x-c];
            }
        }
    }
}*/
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    memset(dp, -1, sizeof dp);
    while(cin >> n){
        ans = solve(n, 0);
        if(ans == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << ans << " ways to produce " << n << " cents change." << endl;
    }
    return 0;
}
