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
const int MAX = 30;

int n, tree, acorn;
string s;
struct uf{
    bitset<30> can, bad, vis;
    int Size[30], link[30];
    void init(){
        REP(i, 0, 30){
            Size[i] = 1; link[i] = i; can[i] = 0;
            bad[i] = 0; vis[i] = 0;
        }
    }
    int parent(int a){
        while(a != link[a]) a = link[a];
        return a;
    }
    void connect(int a, int b){
        a = parent(a);
        b = parent(b);
        if(a == b){
            bad[a] = bad[b] = 1;
            return;
        }
        if(bad[a] || bad[b]){
            bad[a] = bad[b] = 1;
        }
        if(Size[b] > Size[a]) swap(a, b);
        Size[a] += Size[b];
        link[b] = a;
    }
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    while(n--){
        uf dsu;
        dsu.init();
        tree = acorn = 0;
        while(cin >> s && s[0] != '*')
            dsu.connect(s[1]-'A', s[3]-'A');
        cin >> s;
        for(int i = 0; i < s.size(); i += 2)
            dsu.can[s[i]-'A'] = 1;
        REP(i, 0, 28){
            int x = dsu.parent(i);
            if(dsu.can[x] && !dsu.vis[x] && !dsu.bad[x]){
                dsu.Size[x] > 1 ? ++tree: ++acorn;
                dsu.vis[x] = 1;
            }
        }
        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;
    }
    return 0;
}
