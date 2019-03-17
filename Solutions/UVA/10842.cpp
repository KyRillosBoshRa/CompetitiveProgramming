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
#define clr(a, b)                      memset((a), (b), sizeof(a))

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

const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 109;

int n, m, a, b, w, t;
vector<pair<int, ii>> edge;
struct uf{
	int par[N];
	int size[N];
	void init(){
		REP(i, 0, N) size[i] = 1, par[i] = i;
	}
	int root(int a){
		return par[a] == a ? a: par[a] = root(par[a]);
	}
	void unite(int a,int b){
		a = root(a);
		b = root(b);
		if(a == b) return;
		if(size[a] < size[b]) swap(a,b);

		par[b]=a;
		size[a]+=size[b];
	}
	bool same(int a,int b){
		return root(a)==root(b);
	}
};
uf uni;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    REP(c, 1, t+1){
        uni.init();
        edge.clear();
        int ans = INT_MAX;
        cin >> n >> m;
        REP(i, 0, m){
            cin >> a >> b >> w;
            edge.pb(mk(w, mk(a,  b)));
        }
        sort(ALL(edge), greater<pair<int, ii>>());
        for(auto& e:edge){
            if(!uni.same(e.S.F, e.S.S)){
                ans = e.F;
                uni.unite(e.S.F, e.S.S);
            }
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
