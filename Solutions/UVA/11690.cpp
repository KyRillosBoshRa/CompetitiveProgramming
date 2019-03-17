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

int T, n, q, x, y;
vi have;
bool pos;
unordered_map<int, vi> nas;
struct uf{
	vi par, size;
	void init(int n){
		par.resize(n); size.resize(n);
		REP(i, 0, n) size[i]=1, par[i] = i;
	}
	int root(int a){
		if(par[a]==a) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a); b=root(b);
		if(a==b) return;
		if(size[a]<size[b]) swap(a,b);
		par[b]=a;
		size[a]+=size[b];
	}
};
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> T;
    while(T--){
        cin >> n >> q;
        nas.clear();
        have.resize(n);
        pos = true;
        REP(i, 0, n) cin >> have[i];
        uf ds;
        ds.init(n);
        REP(i, 0, q){
            cin >> x >> y;
            ds.unite(x, y);
        }
        REP(i, 0, n) nas[ds.root(i)].pb(have[i]);
        for(auto it = nas.begin(); it != nas.end(); ++it){
            int sum = 0;
            vi& v = it->S;
            REP(i, 0, v.size()){
                sum += v[i];
            }
            if(sum != 0){
                pos = false;
                break;
            }
        }
        if(pos) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
	return 0;
}
