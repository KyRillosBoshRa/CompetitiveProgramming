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
const int N = 109;


struct data{
    int y, a, b;
};
int n;
data arr[N];
void solve(){
    int ans = -1;
    int beg = 0;
    REP(i, 0, n)
        beg = max(beg,arr[i].a);
    REP(i, beg, 10000){
        bool flag = true;
        REP(j, 0, n){
            int tmp = (i-arr[j].a)%(arr[j].b-arr[j].a);
            if(arr[j].a + tmp != arr[j].y){
                flag = false;
                break;
            }
        }
        if(flag){
            ans = i;
            break;
        }
    }
    if(ans == -1)
        cout<< "Unknown bugs detected." <<endl;
    else
        cout<< "The actual year is " << ans << "." <<endl;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int Case = 0;
    while(cin >> n && n){
        int mask = 0;
        cout << "Case #" << ++Case << ':' << endl;
        REP(i, 0, n)
            cin >> arr[i].y >> arr[i].a >> arr[i].b;
        solve();
        cout << endl;
    }
    return 0;
}
