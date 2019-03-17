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

int T, n, x, ans, last;
vi red, blue;
bool b, r;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> T;
    while(T--){
        b = r = 0; ans = last = 0;
        red.clear(); blue.clear();
        cin >> n;
        REP(i, 0, n){
            cin >> x;
            if(x > 0) blue.pb(x);
            else red.pb(-1*x);
        }
        sort(ALL(red));
        sort(ALL(blue));
        int re = 0, le = 0;
        if(0 < red.size() && 0 < blue.size() && red[0] < blue[0]) b = 1, ++re, ++le, ans += 2, last = blue[0];
        else if(0 < red.size() && 0 < blue.size() && red[0] > blue[0]) r = 1, ++re, ++le, ans += 2, last = red[0];
        else{
            if(red.size() > 0) ans = 1, r = 1;
            else if(blue.size() > 0) ans = 1, b = 1;
            else ans = 0;
        }
        while(1){
            if(!r && re < red.size() && red[re] > last) ++ans, r = 1, b = 0, last = red[re], ++re;
            while(!r && re < red.size() && red[re] < last) ++re;
            if(!b && le < blue.size() && blue[le] > last) ++ans, r = 0, b = 1, last = blue[le], ++le;
            while(!b && le < blue.size() && blue[le] < last) ++le;

            if(!r && re >= red.size()) break;
            if(!b && le >= blue.size()) break;
        }
        cout << ans << endl;
    }
    return 0;
}
