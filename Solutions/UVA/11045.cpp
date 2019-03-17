#include <bits/stdc++.h>
using namespace std;

// O(V E^2)
const int INF = 0x3f3f3f3f;
int t, n, m, x, v;
string s;
unordered_map<string, int> idx;
// source = 0, sink = 1021;
const int N = 50;
int sink = 45;
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
  cin >> t;
  idx["XXL"] = 37;
  idx["XL"] = 38;
  idx["L"] = 39;
  idx["XS"] = 40;
  idx["S"] = 41;
  idx["M"] = 42;
  while(t--){
    capacity.assign(N, vector<int>(N));
    adj.assign(N, vector<int>());
    cin >> n >> m;
    int cap = n / 6;
    for(int i = 1; i <= m; ++i){
      adj[sink].push_back(i);
      adj[i].push_back(sink);
      capacity[i][sink] = 1;
    }
    for(auto it = idx.begin(); it != idx.end(); ++it){
      adj[source].push_back(it->second);
      adj[it->second].push_back(source);
      capacity[source][it->second] = cap;
    }
    for(int i = 1; i <= m; ++i){
      cin >> s;
      adj[idx[s]].push_back(i);
      adj[i].push_back(idx[s]);
      capacity[idx[s]][i] = INF;
      cin >> s;
      adj[idx[s]].push_back(i);
      adj[i].push_back(idx[s]);
      capacity[idx[s]][i] = INF;
    }
    if(maxflow(source, sink) == m) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
