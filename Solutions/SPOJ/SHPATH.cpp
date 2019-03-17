#include<bits/stdc++.h>
using namespace std;

int t, n, u, c, x;
string s, s2;
vector<vector<pair<int, int>>> adj;
long long Dijkstra(int source, int distenation) {
  priority_queue <pair<long long, int> , vector<pair<long long, int> >, greater<pair<long long, int> >> Q;
  long long dist[n + 1];
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
  while(t--){
    cin >> n;
    adj.assign(n + 1, vector<pair<int, int>>());
    map<string, int> idx;
    for(int i = 1; i <= n; ++i){
      cin >> s;
      idx[s] = i;
      cin >> x;
      while(x--){
        cin >> u >> c;
        adj[u].emplace_back(i, c);
        adj[i].emplace_back(u, c);
      }
    }
    cin >> x;
    while(x--){
      cin >> s >> s2;
      cout << Dijkstra(idx[s], idx[s2]) << '\n';
    }
  }
  return 0;
}
