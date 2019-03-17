#include <bits/stdc++.h>
using namespace std;

// O(V E^2)
const int N = 200;
const int INF = 0x3f3f3f3f;
int n, m, u, v, c, x;
int sink;
int source = 1;
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
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> n >> m && (n || m)){
    adj.assign(N, vector<int>());
    capacity.assign(N, vector<int>(N));
    sink = n;
    adj[1].push_back(56);
    capacity[1][56] = INF;
    for(int i = 2; i < n; ++i){
      cin >> x >> c;
      adj[x].push_back(x + 55);
      adj[x + 55].push_back(x);
      capacity[x][x + 55] = c;
      capacity[x + 55][x] = c;
    }
    for(int i = 0; i < m; ++i){
      cin >> u >> v >> c;
      adj[u + 55].push_back(v);
      adj[v + 55].push_back(u);
      adj[u].push_back(v + 55);
      adj[v].push_back(u + 55);
      capacity[u + 55][v] = c;
      capacity[v + 55][u] = c;
    }
    cout << maxflow(source, sink) << '\n';
  }
  return 0;
}
