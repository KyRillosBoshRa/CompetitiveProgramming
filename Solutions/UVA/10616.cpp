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

int n, q, x, y, d, m, arr[201];
ll memo[201][21][11];
ll solve(int idx, int x, int cnt){
    if(idx == n)
        return x == 0 && cnt == 0;
    ll& ret = memo[idx][x][cnt];
    if(~ret)
        return ret;
    ll pick = 0;
    if(cnt)
        pick = solve(idx+1, mod(x+arr[idx], d), cnt-1);
    ll leave = solve(idx+1, x, cnt);
    return ret = pick+leave;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int c = 0;
    while(cin >> n >> q && (n||q)){
        cout << "SET " << ++c << ':' << endl;
        REP(i, 0, n)
            cin >> arr[i];
        REP(i, 1, q+1){
            clr(memo, -1);
            cin >> d >> m;
            cout << "QUERY " << i << ": " << solve(0, 0, m) << endl;
        }
    }
    return 0;
}

