const int N = 2e5 + 55;
int n, m, u, v, c, vis[N], vid;
vector<vector<pair<int, int>>> adj;
long long prim(int v) {
  ++vid;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  long long res = 0;
  pq.emplace(0, v);
  while (!pq.empty()) {
    int c = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (vis[v] == vid) continue;
    vis[v] = vid;
    res += c;
    for (auto x : adj[v]) {
      if (vis[x.first] == vid) continue;
      pq.emplace(x.second, x.first);
    }
  }
  return res;
}