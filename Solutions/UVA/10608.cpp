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

int T, n, m, x, y;
int parent[N], Size[N];
void init(){
    REP(i, 1, n+1)
        parent[i] = i, Size[i] = 1;
}
int find_parent(int a){
    while(a != parent[a]) a = parent[a];
    return a;
}
void uni(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return;
    if(Size[a] < Size[b]) swap(a, b);
    Size[a] += Size[b];
    parent[b] = a;
}
int find_max(){
    bool vis[n+1] = {0};
    int mx = 0;
    REP(i, 1, n+1){
        if(vis[find_parent(i)]) continue;
        vis[find_parent(i)] = 1;
        mx = max(mx, Size[find_parent(i)]);
    }
    return mx;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> T;
    while(T--){
        cin >> n >> m;
        init();
        REP(i, 0, m){
            cin >> x >> y;
            uni(x, y);
        }
        cout << find_max() << endl;
    }
	return 0;
}
