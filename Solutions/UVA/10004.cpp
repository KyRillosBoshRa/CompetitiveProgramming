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
const int MAX = 505;

int n, m, x, y;
queue<int> q;
bool bfs(int node, int col[], vi adj[]){
    q.push(node);
    col[node] = 0;
    bool bi = true;
    while(!q.empty() && bi){
        int s = q.front(); q.pop();
        for(int u:adj[s]){
            if(col[u] == -1){
                col[u] = 1-col[s];
                q.push(u);
            }
            else if(col[u] == col[s]){
                bi = false;
                break;
            }
        }
    }
    return bi;
}
bool process(){
    vi adj[n+1];
    int col[n+1];
    while(!q.empty()) q.pop();
    memset(col, -1, sizeof(col));
    REP(i, 0, m){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    return bfs(0, col, adj);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n && n){
        cin >> m;
        if (process()) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
