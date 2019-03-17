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
const int N = 1100009;

template<class T> inline T max(T a, T b, T c){return max(a, max(b, c));}

int n = 1024000, t[4*N];
char lazy[4*N];
void build(int a[], int v = 1, int tl = 0, int tr = n-1) {
    if(tl == tr){
        t[v] = a[tl];
    }
    else{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void update_lazy(int v, char opr){
    if(opr==0)
        return;
    if(opr=='I'){
        switch(lazy[v]){
        case 'F':
            lazy[v] = 'E';
            break;
        case 'E':
            lazy[v] = 'F';
            break;
        case 'I':
            lazy[v] = 0;
            break;
        default:
            lazy[v] = 'I';
        }
    }
    else
        lazy[v] = opr;
}
void update_opr(int v, int tl, int tr, int opr){
    if(opr==0)
        return;
    switch(opr)
    {
    case 'E':
         t[v] = 0;
         break;
    case 'F':
        t[v] = (tr-tl+1);
        break;
    default:
        t[v] = (tr-tl+1) - t[v];

    }
}
void propagate(int v, int tl, int tr){
		int mid = (tl + tr)/2;
		update_lazy(v*2, lazy[v]);
		update_lazy(v*2+1, lazy[v]);
		update_opr(v*2, tl, mid, lazy[v]);
		update_opr(v*2+1, mid+1, tr, lazy[v]);
		lazy[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, char new_val) {
    if (l > tr || r < tl)
        return;
    if(l <= tl && tr <= r){
        update_lazy(v, new_val);
        update_opr(v, tl, tr, new_val);
    }
    else{
        propagate(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, r, new_val);
        update(v*2+1, tm+1, tr, l, r, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl)
        return 0;
    if (l <= tl && r >= tr)
        return t[v];
    propagate(v, tl, tr);
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, r)
           + sum(v*2+1, tm+1, tr, l, r);
}
int T, m, q, arr[N], arrC, a, b, cnt, Case;
string s, tmp;
char c;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> T;
    while(T--){
        cout << "Case " << ++Case << ":\n";
        s.clear();
        cnt = 0;
        memset(lazy, 0, sizeof(lazy));
        memset(arr, 0, sizeof(arr));
        cin >> m;
        REP(i, 0, m){
            cin >> a >> tmp;
            REP(j, 0, a)
                s += tmp;
        }
        REP(i, 0, s.size())
            if(s[i] == '1')
                arr[i] = 1;
        build(arr);
        cin >> q;
        REP(i, 0, q){
            cin >> c >> a >> b;
            if(c == 'S')
                cout << 'Q' << ++cnt << ": " << sum(1, 0, n-1, a, b) << endl;
            else
                update(1, 0, n-1, a, b, c);
        }
    }
    return 0;
}
