long long Dijkstra(int source, int distenation) {
  priority_queue <pair<long long, int> , vector<pair<long long, int> >, greater<pair<long long, int> >> Q;
  long long dist[N];
  int par[N];
  memset(dist, 0x3f, sizeof(dist));
  memset(par, -1, sizeof(par));
  dist[source] = 0;
  Q.emplace(0, source);
  while (!Q.empty()) {
    int a = Q.top().second; Q.pop();
    for (auto u : adj[a]){
      int b = u.first, w = u.second;
      if (dist[a] + w < dist[b]) {
        dist[b] = dist[a] + w;
        Q.emplace(dist[b], b);
        par[b] = a;
			}
		}
	}
	return dist[distenation];
}