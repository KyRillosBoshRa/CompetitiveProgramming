#include <bits/stdc++.h>
using namespace std;

// O(V E^2)
const int N = 2200;
const int INF = N;
int n, m, p;
string s[N];
int sink = 2198;
int source = 2199;
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
int dx[] = {0,  0,  1, -1};
int dy[] = {1, -1,  0,  0};
bool valid(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < m;
}
inline int out(int x){return x + 1001;}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> n >> m >> p){
    adj.assign(N, vector<int>());
    capacity.assign(N, vector<int>(N));
    for(int i = 0; i < n; ++i) cin >> s[i];
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if(s[i][j] == '~') continue;
        if(s[i][j] == '*'){
          adj[i * m + j].push_back(source);
          adj[source].push_back(i * m + j);
          capacity[source][i * m + j] = 1;
          s[i][j] = '.';
        }
        if(s[i][j] == '.'){
          adj[i * m + j].push_back(out(i * m + j));
          adj[out(i * m + j)].push_back(i * m + j);
          capacity[i * m + j][out(i * m + j)] = 1;
        }
        if(s[i][j] == '#'){
          adj[i * m + j].push_back(sink);
          adj[sink].push_back(i * m + j);
          capacity[i * m + j][sink] = p;
          s[i][j] = '@';
        }
        if(s[i][j] == '@'){
          adj[i * m + j].push_back(out(i * m + j));
          adj[out(i * m + j)].push_back(i * m + j);
          capacity[i * m + j][out(i * m + j)] = INF;
        }
        for(int k = 0; k < 4; ++k){
          if(valid(i + dx[k], j + dy[k])){
            adj[out(i * m + j)].push_back((i + dx[k]) * m + j + dy[k]);
            adj[(i + dx[k]) * m + j + dy[k]].push_back(out(i * m + j));
            capacity[out(i * m + j)][(i + dx[k]) * m + j + dy[k]] = INF;
          }
        }
      }
    }
    cout << maxflow(source, sink) << '\n';
  }
  return 0;
}
