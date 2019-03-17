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

int x, y, r, c, n, C;
unordered_map<int, bool> gotr, gotc;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> r >> c >> n && (r || c || n)){
        gotr.clear(); gotc.clear();
        bool solved = 0;
        REP(i, 0, n){
            cin >> x >> y;
            gotr[x] = gotc[y] = true;
        }
        cin >> x >> y;
        int dr[] = {0, 0, 0, 1, -1};
        int dc[] = {0, 1, -1, 0, 0};
        REP(i, 0, 5){
            if(x + dr[i] >= 0 && x + dr[i] < r && y + dc[i] >= 0 && y + dc[i] < c && !gotr[x+dr[i]] && !gotc[y+dc[i]])
                solved = true;
        }
        if(solved) cout << "Case " << ++C << ':' << " Escaped again! More 2D grid problems!" << endl;
        else cout << "Case " << ++C << ':' << " Party time! Let's find a restaurant!" << endl;
    }
	return 0;
}
