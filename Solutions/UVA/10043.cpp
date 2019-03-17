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

int t, n;
double a[101], b[101], ans;
//map<pair<pair<double, double>, pair<double, double> >, double> adj; //node 1, node 2, val
map<double, vector<pair<pair<double, double>, pair<double, double> > > > edge_list; //sorted edge list
map<pair<double, double>, pair<double, double> > par;
map<pair<double, double>, int > cz;
bool ss(pair<double, double> a, pair<double, double> b){
    if(fabs(a.F-b.F) > eps || fabs(a.S-b.S) > eps)
        return false;
    return true;
}
pair<double, double> root(pair<double, double> a){
    return ss(par[a], a) ? a: par[a] = root(par[a]);
}
void unite(pair<double, double> a,pair<double, double> b){
    a = root(a);
    b = root(b);
    if(cz[a] < cz[b]) swap(a,b);

    par[b] = a;
    cz[a] += cz[b];
}
bool same(pair<double, double> a,pair<double, double> b){
    return ss(root(a),root(b));
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
        par.clear();
        cz.clear();
        ans = 0;
        cin >> n;
        REP(i, 0, n){
            cin >> a[i] >> b[i];
            par[mk(a[i], b[i])] = mk(a[i], b[i]);
            cz[mk(a[i], b[i])] = 1;
        }
        REP(i, 0, n)
            REP(j, 0, n){
                if(i == j) continue;
                double x = fabs(a[i]-a[j]);
                double y = fabs(b[i]-b[j]);
                double cost = sqrt(x*x + y*y);
//                adj[mk(mk(a[i], b[i]), mk(a[j], b[j]))] = cost;
//                adj[mk(mk(a[j], b[j]), mk(a[i], b[i]))] = cost;
                edge_list[cost].pb(mk(mk(a[j], b[j]), mk(a[i], b[i])));
            }
//        for(auto it = adj.begin(); it != adj.end(); ++it)
//            edge_list[it->S] = it->F;
        for(auto it = edge_list.begin(); it != edge_list.end(); ++it){
            REP(i, 0, it->S.size()){
                if(!same(it->S[i].F, it->S[i].S)){
                    ans += it->F;
                    unite(it->S[i].F, it->S[i].S);
                }
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
        if(t) cout << endl;
    }
	return 0;
}
