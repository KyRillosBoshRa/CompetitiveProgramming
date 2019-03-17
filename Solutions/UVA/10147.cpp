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
#define clr(a, b)                      memset((a), (b), sizeof(a))
#define F                              first
#define S                              second
#define popcnt(x)                      __builtin_popcount(x)
#define WHITE                          0
#define GRAY                           1
#define BLACK                          2
#define bye                            exit(0)
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
const int N = (int)1e5+5;
int MOD = (int)1e9+7;

int t, n, m, x, y;
int a[1001], b[1001];
bool found;
//map<pair<pair<double, double>, pair<double, double> >, double> adj; //node 1, node 2, val
vector<pair<double, ii> > edge_list; //sorted edge list
int par[N];
int cz[N];
void init(int n){
    REP(i, 0, n+1) cz[i] = 1, par[i] = i;
}
int root(int a){
    return par[a] == a ? a: par[a] = root(par[a]);
}
void unite(int a, int b){
    a = root(a);
    b = root(b);
    if(cz[a] < cz[b]) swap(a,b);

    par[b] = a;
    cz[a] += cz[b];
}
bool same(int a, int b){
    return (root(a) == root(b));
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    while(t--){
//        adj.clear();
        edge_list.clear();
        found = false;
        cin >> n;
        init(n);
        REP(i, 0, n){
            cin >> a[i] >> b[i];
        }
        REP(i, 0, n)
            REP(j, 0, n){
                if(i == j) continue;
                int x = abs(a[i]-a[j]);
                int y = abs(b[i]-b[j]);
                double cost = sqrt(x*x + y*y);
//                adj[mk(mk(a[i], b[i]), mk(a[j], b[j]))] = cost;
//                adj[mk(mk(a[j], b[j]), mk(a[i], b[i]))] = cost;
                edge_list.pb(mk(cost, mk(i+1, j+1)));
            }
//        for(auto it = adj.begin(); it != adj.end(); ++it)
//            edge_list[it->S] = it->F;
        sort(ALL(edge_list));
        cin >> m;
        REP(i, 0, m){
            cin >> x >> y;
            unite(x, y);
        }
        REP(i, 0, edge_list.size()){
            if(!same(edge_list[i].S.F, edge_list[i].S.S)){
                unite(edge_list[i].S.F, edge_list[i].S.S);
                cout << edge_list[i].S.F << ' ' << edge_list[i].S.S << endl;
                found = true;
            }
        }
        if(!found) cout << "No new highways need" << endl;
        if(t) cout << endl;
    }
	return 0;
}
