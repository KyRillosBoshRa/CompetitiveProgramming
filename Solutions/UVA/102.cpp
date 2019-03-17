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
const int N = 100009;

int arr[9], mn, a;
string ans;
// brown, green and clear
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin.peek() != EOF){
        mn = numeric_limits<int>::max();
        REP(i, 0, 9) cin >> arr[i]; cin.ignore();
//        case 1 GCB
        a = 0;
        a += arr[4]+arr[7];
        a += arr[2]+arr[8];
        a += arr[0]+arr[3];
        if(a <= mn){
            mn = a;
            ans = "GCB";
        }
//        case 2 GBC
        a = 0;
        a += arr[4]+arr[7];
        a += arr[0]+arr[6];
        a += arr[2]+arr[5];
        if(a <= mn){
            mn = a;
            ans = "GBC";
        }
//        case 3 CGB
        a = 0;
        a += arr[5]+arr[8];
        a += arr[1]+arr[7];
        a += arr[0]+arr[3];
        if(a <= mn){
            mn = a;
            ans = "CGB";
        }
//        case 4 CBG
        a = 0;
        a += arr[5]+arr[8];
        a += arr[0]+arr[6];
        a += arr[1]+arr[4];
        if(a <= mn){
            mn = a;
            ans = "CBG";
        }
//        case 5 BGC
        a = 0;
        a += arr[3]+arr[6];
        a += arr[1]+arr[7];
        a += arr[2]+arr[5];
        if(a <= mn){
            mn = a;
            ans = "BGC";
        }
//        case 6 BCG
        a = 0;
        a += arr[3]+arr[6];
        a += arr[2]+arr[8];
        a += arr[1]+arr[4];
        if(a <= mn){
            mn = a;
            ans = "BCG";
        }
        cout << ans << ' ' << mn << endl;
    }
    return 0;
}
