#include<bits/stdc++.h>
using namespace std;

const int N = 2e4 + 55;
int t, n, m, s, d, u, v, c;
vector<vector<pair<int, int>>> adj;
long long Dijkstra(int source, int distenation) {
  priority_queue <pair<long long, int> , vector<pair<long long, int> >, greater<pair<long long, int> >> Q;
  long long dist[n];
  memset(dist, 0x3f, sizeof(dist));
  dist[source] = 0;
  Q.emplace(0, source);
  while (!Q.empty()) {
    int a = Q.top().second; Q.pop();
    for (auto u : adj[a]){
      int b = u.first, w = u.second;
      if (dist[a] + w < dist[b]) {
        dist[b] = dist[a] + w;
        Q.emplace(dist[b], b);
      }
		}
	}
	return dist[distenation];
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  cin >> t;
  int cs = 0;
  while(t--){
    cin >> n >> m >> s >> d;
    adj.assign(n, vector<pair<int, int>>());
    for(int i = 0; i < m; ++i){
      cin >> u >> v >> c;
      adj[u].emplace_back(v, c);
      adj[v].emplace_back(u, c);
    }
    long long ans = Dijkstra(s, d);
    cout << "Case #" << ++cs << ": ";
    if(ans != 0x3f3f3f3f3f3f3f3f) cout << ans << '\n';
    else cout << "unreachable\n";
  }
  return 0;
}
