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
const int N = 509;

int n, m, s, d, a, b, w;
map<int, map<int, int> > adj;
set<int> parent[N];
ll Dijkstra(int source, int distenation){
    priority_queue <pair<ll, int> , vector<pair<ll, int> >, greater<pair<ll, int> >> Q;
	ll dist[N];
	clr(dist, 0x3f);
//	clr(parent, -1);
	dist[source] = 0;
	Q.push(mk(0, source));
	while (!Q.empty()){
		int a = Q.top().S; Q.pop();
		for(auto u : adj[a]){
			int b = u.F, w = u.S;
			if (dist[a] + w <= dist[b]){
				if(dist[a] + w == dist[b])
                    parent[b].insert(a);
                else{
                    parent[b].clear();
                    parent[b].insert(a);
                }
				dist[b] = dist[a] + w;
				Q.push(mk(dist[b], b));
			}
		}
	}
	return dist[distenation];
}
void delete_path(int x = d){
    if(parent[x].empty())
        return;
    for(auto it = parent[x].begin(); it != parent[x].end(); ++it){
        adj[*it].erase(x);
        delete_path(*it);
    }
}
//bool has_bad(){
//    int x = d;
//    while(parent[x] != -1){
//        if(bad.find(mk(parent[x], x)) != bad.end())
//            return true;
//        x = parent[x];
//    }
//    return false;
//}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n >> m && (n || m)){
        adj.clear();
        REP(i, 0, N)
            parent[i].clear();
        cin >> s >> d;
        REP(i, 0, m){
            cin >> a >> b >> w;
            adj[a][b] = w;
//            adj[b].pb({a, w});
        }
        ll ans = Dijkstra(s, d);
        delete_path();
        ans = Dijkstra(s, d);
        cout << (ans == INF ? -1: ans) << endl;
    }
    return 0;
}
