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

int T, n, m;
string a[100];
int dr[] = {-1, 0, 0};
int dc[] = {0, -1, 1};
string word = "@IEHOVA#";
vector<string> ans;
bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}
void solve(int x, int y, int idx = 1){
    if(idx == word.size())
        return;
    if(valid(x-1, y) && a[x-1][y] == word[idx]){
            ans.pb("forth");
            solve(x-1, y, idx+1);
    }
    else if(valid(x, y-1) && a[x][y-1] == word[idx]){
            ans.pb("left");
            solve(x, y-1, idx+1);
    }
    else if(valid(x, y+1) && a[x][y+1] == word[idx]){
            ans.pb("right");
            solve(x, y+1, idx+1);
    }
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	cin >> T;
	while(T--){
        ans.clear();
        cin >> n >> m;
        REP(i, 0, n)
            cin >> a[i];
        REP(i, 0, n)
            REP(j, 0, m)
                if(a[i][j] == '@')
                    solve(i, j);
        REP(i, 0, ans.size())
            cout << ans[i] << " \n"[i+1 == ans.size()];
	}
	return 0;
}
