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

int n, c, a, b;
struct uf{
	vi par, Size;
	uf(int n){
	    par.resize(n);
	    Size.resize(n);
		REP(i, 0, n) Size[i] = 1, par[i] = i;
	}
	int root(int a){
		if(par[a] == a) return a;
		return par[a] = root(par[a]);
	}
	void unite(int a,int b){
		a = root(a); b = root(b);
		if(a == b) return;
		if(Size[a]<Size[b]) swap(a,b);

		par[b] = a;
		Size[a] += Size[b];
	}
	bool same(int a,int b){
		return root(a) == root(b);
	}
};
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    uf uf(n*2+9);
    while(cin >> c >> a >> b && c){
        if(c == 1){
            if(uf.same(a, b+n) || uf.same(a+n, b))
                cout << -1 << endl;
            else{
                uf.unite(a, b);
                uf.unite(a+n, b+n);
            }
        }
        else if(c == 2){
            if(uf.same(a, b))
                cout << -1 << endl;
            else{
                uf.unite(a, b+n);
                uf.unite(a+n, b);
            }
        }
        else if(c == 3){
            if(uf.same(a, b))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else{
            if(uf.same(a, b+n) || uf.same(a+n, b))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
	return 0;
}
