#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 55;
int n, m, u, v, c, vis[N], vid;
vector<vector<pair<int, int>>> adj;
long long prim(int v){
  ++vid;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  long long res = 0;
  pq.emplace(0, v);
  while(!pq.empty()){
    int c = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if(vis[v] == vid) continue;
    vis[v] = vid;
    res += c;
    for(auto x: adj[v]){
      if(vis[x.first] == vid) continue;
      pq.emplace(x.second, x.first);
    }
  }
  return res;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  while(cin >> n >> m && n && m){
    long long tot = 0;
    adj.assign(n + 1, vector<pair<int, int>>());
    for(int i = 0; i < m; ++i){
      cin >> u >> v >> c;
      tot += c;
      adj[u].emplace_back(v, c);
      adj[v].emplace_back(u, c);
    }
    cout << tot - prim(0) << '\n';
  }  
  return 0;
}
