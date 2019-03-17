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

template<class T> inline T max(T a, T b, T c){return max(a, max(b, c));}

int n, t[4*N];
void build(int a[], int v = 1, int tl = 0, int tr = n-1) {
    if(tl == tr){
        t[v] = a[tl];
    }
    else{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}
int get_max(int l, int r, int v = 1, int tl = 0, int tr = n-1) {
    if(l > r)
        return -INF;
    if(l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return max(get_max(l, min(r, tm), v*2, tl, tm)
           , get_max(max(l, tm+1), r, v*2+1, tm+1, tr));
}
void update(int pos, int new_value, int v = 1, int tl = 0, int tr = n-1) {
    if(tl == tr){
        t[v] = new_value;
    }
    else{
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_value, v*2, tl, tm);
        else
            update(pos, new_value, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}
int a[N], q, ans, x, y, f[N];
unordered_map<int, int> L, R, freq;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n >> q && n){
        freq.clear();
        L.clear();
        R.clear();
        ans = 0;
        REP(i, 0, n){
            cin >> a[i];
            ++freq[a[i]];
            if(L.find(a[i]) == L.end()) L[a[i]] = i;
            R[a[i]] = i;
        }
        REP(i, 0, n)
            f[i] = freq[a[i]];
        build(f);
        REP(i, 0, q){
            cin >> x >> y; --x; --y;
            if(a[x] == a[y])
                cout << y-x+1 << endl;
            else if((!x || a[x] != a[x-1]) && (y == n-1 || a[y] != a[y+1]))
                cout << get_max(x, y) << endl;
            else if ((x && a[x] == a[x-1]) && (y == n-1 || a[y] != a[y+1]))
                cout << max(R[a[x]]-x+1, get_max(R[a[x]]+1, y)) << endl;
            else if((!x || a[x] != a[x-1]) && (y != n-1 && a[y] == a[y+1]))
                cout << max(get_max(x, L[a[y]]-1), y-L[a[y]]+1) << endl;
            else if((x && a[x] == a[x-1]) && (y != n-1 && a[y] == a[y+1]))
                cout << max(y-L[a[y]]+1, R[a[x]]-x+1, get_max(R[a[x]]+1, L[a[y]]-1)) << endl;
        }
    }
    return 0;
}
