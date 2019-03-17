#include <bits/stdc++.h>
using namespace std;

// O(V E^2)
const int INF = 0x3f3f3f3f;
char app;
int num_user;
string comps;
// source = 20, sink = 30;
vector<vector<int>> capacity;
vector<vector<int>> adj;
int parent[101];
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
  freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin.peek() != EOF){
    capacity.assign(100, vector<int>(100));
    adj.assign(100, vector<int>());
    for(int i = 0; i < 10; ++i)
      adj[30].push_back(i), adj[i].push_back(30), capacity[i][30] = 1;
    int tot = 0;
    while(isalpha(cin.peek())){
      cin.get(app);
      cin >> num_user >> comps; cin.ignore(); comps.pop_back();
      tot += num_user;
      adj[app].push_back(20);
      adj[20].push_back(app);
      capacity[20][app] = num_user;
      for(auto c: comps){
        adj[app].push_back(c - '0');
        adj[c - '0'].push_back(app);
        capacity[app][c - '0'] = INF;
      }
    }
    if(maxflow(20, 30) != tot) cout << "!\n";
    else{
      char ans[11];
      for(int i = 0; i < 10; ++i){
        ans[i] = '_';
        for(int j = 'A'; j <= 'Z'; ++j){
          if(capacity[i][j] == 1) ans[i] = j;
        }
      }
      cout << ans << '\n';
    }
    cin.ignore();
  }
  return 0;
}
