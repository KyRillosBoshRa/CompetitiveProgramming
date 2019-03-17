#include <bits/stdc++.h>
using namespace std;

// O(V E^2)
const int INF = 0x3f3f3f3f;
int n, m, x, v;
// source = 0, sink = 1021;
const int N = 1025;
int sink = 1022;
int source = 0;
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
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> n >> m && (n || m)){
    capacity.assign(N, vector<int>(N));
    adj.assign(N, vector<int>());
    int tot = 0;
    for(int i = 1; i <= n; ++i) {
      cin >> v;
      tot += v;
      adj[sink].push_back(i + 1000);
      adj[i + 1000].push_back(sink);
      capacity[i + 1000][sink] = v;
    }
    for(int i = 1; i <= m; ++i){
      adj[source].push_back(i);
      adj[i].push_back(source);
      capacity[source][i] = 1;
      cin >> x;
      while(x--){
        cin >> v;
        adj[v + 1000].push_back(i);
        adj[i].push_back(v + 1000);
        capacity[i][v + 1000] = INF;
      }
    }
    if(maxflow(source, sink) == tot){
      cout << 1 << '\n';
      vector<int> ans[30];
      for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
          if(capacity[i + 1000][j]){
            ans[i].push_back(j);
          }
        }
      }
      for(int i = 1; i <= n; ++i){
        for(int j = 0; j < ans[i].size(); ++j){
          cout << ans[i][j] << " \n"[j == ans[i].size() - 1];
        }
      }
    }else{
      cout << 0 << '\n';
    }
  }
  return 0;
}
