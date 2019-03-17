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

const int INF = 0x3f3f3f3f;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 1e5+5;

template<class T>inline T mod(T a, int b){return (b + (a%b)) % b;}

int n, m, cz;
vector<string> sec;
vector<string> ans;
bool solved;
unordered_map<string, bool> vis;
unordered_map<string, vector<string>> adj;
void solve(string ans = ""){
    if(ans.size() == m){
        sec.pb(ans);
        return;
    }
    REP(i, 0, n)
        solve(ans + char(i+'0'));
}
string str;
void f(string v, int cnt = 0){
    if(cnt == pow(n, m) && v == str && !solved){
        solved = true;
        REP(i, 0, ans.size()-1)
            cout << ans[i][0];
        cout << endl;
        return;
    }
    if(vis[v] || solved)
        return;
    vis[v] = 1;
    for(string c:adj[v]){
        ans.pb(c);
        f(c, cnt+1);
        ans.pop_back();
    }
    vis[v] = 0;
}
int main(){
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> m >> n){
        solved = false;
        sec.clear();
        vis.clear();
        adj.clear();
        solve();
        REP(i, 0, sec.size()){
            string tmp = sec[i];
            tmp.erase(0, 1);
            REP(j, 0, n)
                adj[sec[i]].pb(tmp + char(j+'0'));
        }
        REP(i, 0, sec.size())
            if(!solved){
                str = sec[i];
                ans.pb(sec[i]);
                f(sec[i]);
                ans.pop_back();
            }
    }
    return 0;
}

