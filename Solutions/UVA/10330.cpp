#include <bits/stdc++.h>
using namespace std;

// O(V E^2)
const int N = 300;
const int INF = 0x3f3f3f3f;
int n, m, p, u, v, c;
int sink = 299;
int source = 289;
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
  int new_flow;

  while (new_flow = bfs(s, t)) {
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
inline int out(int x){return x + 101;}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> n){
    adj.assign(N, vector<int>());
    capacity.assign(N, vector<int>(N));
    for(int i = 1; i <= n; ++i){
      cin >> c;
      adj[i].push_back(out(i));
      adj[out(i)].push_back(i);
      capacity[i][out(i)] = c;
    }
    cin >> m;
    for(int i = 1; i <= m; ++i){
      cin >> u >> v >> c;
      adj[out(u)].push_back(v);
      adj[v].push_back(out(u));
      capacity[out(u)][v] = c;
    }
    cin >> u >> v;
    for(int i = 0; i < u; ++i){
      cin >> c;
      adj[source].push_back(c);
      adj[c].push_back(source);
      capacity[source][c] = INF;
    }
    for(int i = 0; i < v; ++i){
      cin >> c;
      adj[out(c)].push_back(sink);
      adj[sink].push_back(out(c));
      capacity[out(c)][sink] = INF;
    }
    cout << maxflow(source, sink) << '\n';
  }
  return 0;
}
