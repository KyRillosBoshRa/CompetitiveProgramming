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
const int MOD = (int)1e9+7;

int n, t;
vector<string> ans;
int vis[21][21];
string grid[21];
int dr[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dc[] = {-1, 0, 1, -1, 0, 1, -1, 1};
bool valid(int a, int b){
    if(a < 0 || a >= n || b < 0 || b >= n)
        return false;
    return true;
}
void solve(int x, int y, string word){
    vis[x][y] = true;
    if(word.size() > 2) ans.pb(word);
    REP(i, 0, 8){
        if(valid(x+dr[i], y+dc[i]) && !vis[x+dr[i]][y+dc[i]] && grid[x+dr[i]][y+dc[i]] > grid[x][y]){
            solve(x+dr[i], y+dc[i], word+grid[x+dr[i]][y+dc[i]]);
        }
    }
    vis[x][y] = false;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    REP(x, 0, t){
        if(x) cout << endl;
        cin >> n;
        ans.clear();
        REP(i, 0, n)
            cin >> grid[i];
        string tmp;
        REP(i, 0, n)
            REP(j, 0, n){
                tmp += grid[i][j];
                solve(i, j, tmp);
                tmp.pop_back();
            }
        sort(ALL(ans), [&](const string& a, const string& b){
                if(a.size() == b.size())
                    return a < b;
                return a.size() < b.size();
            });
        UNIQUE(ans);
        for(string& a:ans)
            cout << a << endl;
    }
	return 0;
}
