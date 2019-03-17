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

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 200009;

int n, m;
ii arr[20];
ii l, r;
typedef bitset<20> MASK;
bool solve(int prv, int cnt, MASK mask){
    if(cnt == n)
        return prv == r.F;
    REP(i, 0, m){
        if(!mask[i] && arr[i].F == prv){
            MASK tmp = mask;
            tmp[i] = 1;
            if(solve(arr[i].S, cnt+1, tmp))
                return true;
        }
        else if(!mask[i] && arr[i].S == prv){
            MASK tmp = mask;
            tmp[i] = 1;
            if(solve(arr[i].F, cnt+1, tmp))
                return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n && n){
        cin >> m;
        cin >> l.F >> l.S;
        cin >> r.F >> r.S;
        REP(i, 0, m)
            cin >> arr[i].F >> arr[i].S;
        if(solve(l.S, 0, MASK()))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
