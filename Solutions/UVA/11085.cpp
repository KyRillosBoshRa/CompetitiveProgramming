#include <bits/stdc++.h>
//#include"stdafx.h"
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
#define WHITE 0
#define GRAY  1
#define BLACK 2
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
const int N = 9;

int row[N], col[N], diag1[N*2], diag2[N*2], tmp[N][N], ans;
vector<vi> a;
void _8Queen(int n, int x = 1){
    if(!n){
        vi x; x.pb(0);
        REP(i, 1, N)
            REP(j, 1, N)
                if(tmp[j][i])
                    x.pb(j);
        a.pb(x);
        return;
    }
    REP(i, x, N){
        REP(j, 1, N){
            if(!row[j] && !col[i] && !diag1[i+j] && !diag2[N+(i-j)]){
                tmp[j][i] = row[j] = col[i] = diag1[i+j] = diag2[N+(i-j)] = 1;
                _8Queen(n-1, i);
                tmp[j][i] = row[j] = col[i] = diag1[i+j] = diag2[N+(i-j)] = 0;
            }
        }
    }
}
int ss[N], c;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_intJUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	a.pb(vi(0));
	_8Queen(8);
	while(1){
        REP(i, 1, N)
            cin >> ss[i];
        if(cin.eof()) break;
        cout << "Case " << ++c << ": ";
        ans = numeric_limits<int>::max();
        REP(i, 1, a.size()){
            int diff = 0;
            REP(j, 1, N)
                diff += (a[i][j] != ss[j]);
            ans = min(ans, diff);
        }
        cout << ans << endl;
    }
	return 0;
}
