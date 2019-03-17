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

int n, k, price[101], val[101], goal;
int memo[101][10001];
int solve(int idx, int cnt){
    if((cnt > k && k < 1800) || (cnt > k + 200))
        return -INF;
    if(idx == n){
        if(cnt > k && cnt <= 2000)
            return -INF;
        return 0;
    }
    int& ret = memo[idx][cnt];
    if(~ret)
        return ret;
    int pick = val[idx] + solve(idx+1, cnt+price[idx]);
    int leave = solve(idx+1, cnt);
    return ret = max(pick, leave);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> k >> n){
        REP(i, 0, n)
            cin >> price[i] >> val[i];
        clr(memo, -1);
        cout << solve(0, 0) << endl;
    }
    return 0;
}

