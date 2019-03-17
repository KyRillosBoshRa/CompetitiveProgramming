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
const int N = 1000009;

int n, T, x, pos, Case;
int teamN[N];
string s;
unordered_map<int, int> position;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> T && T){
        cout << "Scenario #" << ++Case << endl;
        pos = 0;
        position.clear();
        REP(i, 0, T){
            cin >> n;
            REP(o, 0, n)
                cin >> x, teamN[x] = i;
        }
        vector<queue<int> >ans;
        while(cin >> s && s != "STOP"){
            if(s == "ENQUEUE"){
                cin >> x;
                if(position.find(teamN[x]) != position.end()){
                    ans[position[teamN[x]]].push(x);
                }
                else{
                    queue<int> tmp; tmp.push(x);
                    position[teamN[x]] = ans.size();
                    ans.pb(tmp);
                }
            }
            else if(s == "DEQUEUE"){
                int tmp = ans[pos].front();
                cout << tmp << endl; ans[pos].pop();
                if(ans[pos].empty()){
                    ++pos;
                    position.erase(position.find(teamN[tmp]));
                }
            }
        }
        cout << endl;
    }
	return 0;
}
