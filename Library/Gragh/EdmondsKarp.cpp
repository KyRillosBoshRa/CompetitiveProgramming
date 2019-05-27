// O(V E^2)
const int INF = 1e9+1;
const int N = 505;
vector<vector<int>> capacity;
vector<vector<int>> adj;
int parent[N];
int bfs(int s, int t) {
  memset(parent, -1, sizeof(parent));
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});

  while(!q.empty()){
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();
    for(int next: adj[cur]) {
      if(parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }
  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;

  while (int new_flow = bfs(s, t)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}