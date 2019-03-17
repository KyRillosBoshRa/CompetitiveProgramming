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
const int N = 1000009;

int t[N];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] * t[v*2+1];
    }
}

int product(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl)
        return 1;
    if (l <= tl && r >= tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return product(v*2, tl, tm, l, min(r, tm)) * product(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_value) {
    if (tl == tr) {
        t[v] = new_value;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_value);
        else
            update(v*2+1, tm+1, tr, pos, new_value);
        t[v] = t[v*2] * t[v*2+1];
    }
}
int n, q, x, y, arr[N];
char c;
string ans;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n >> q){
        ans = "";
        REP(i, 0, n){
            cin >> arr[i];
            if(arr[i] > 0) arr[i] = 1;
            else if(arr[i] < 0) arr[i] = -1;
        }
        build(arr, 1, 0, n-1);
        REP(i, 0, q){
            cin >> c >> x >> y; --x;
            if(c == 'C'){
                if(y > 0) y = 1;
                else if(y < 0) y = -1;
                update(1, 0, n-1, x, y);
            }
            else{
                int tmp = product(1, 0, n-1, x, y-1);
                if(tmp > 0) ans += '+';
                else if(tmp < 0) ans += '-';
                else ans += '0';
            }
        }
        cout << ans << endl;
    }
    return 0;
}
