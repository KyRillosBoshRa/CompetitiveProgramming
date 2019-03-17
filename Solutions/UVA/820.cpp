#include <bits/stdc++.h>
using namespace std;

int n, u, v, c, m;
const int INF = 1e9+1;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
  fill(parent.begin(), parent.end(), -1);
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
  vector<int> parent(n + 1);
  int new_flow;

  while (new_flow = bfs(s, t, parent)) {
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
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  int C = 0;
  while(cin >> n && n){
    int s, t;
    cout << "Network " << ++C << '\n';
    cin >> s >> t >> m;
    capacity.assign(n + 1, vector<int>(n + 1));
    adj.clear();
    adj.resize(n + 1);
    for(int i = 0; i < m; ++i){
      cin >> u >> v >> c;
      adj[u].push_back(v);
      adj[v].push_back(u);
      capacity[u][v] += c;
      capacity[v][u] += c;
    }
    cout << "The bandwidth is " << maxflow(s, t) << ".\n\n";
  }
  return 0;
}
