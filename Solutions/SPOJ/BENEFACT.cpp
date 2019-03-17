#include<bits/stdc++.h>
using namespace std;

int t, n, u, v, c;
int crr, longest;
vector<vector<pair<int, int>>> adj;
void dfs(int v,int par = -1, int lvl = 0){
  if(lvl > crr){
    crr = lvl;
    longest = v;
  }
  for(auto a: adj[v]){
    int u = a.first;
    int w = a.second;
    if(u == par) continue;
    dfs(u, v, lvl+w);
  }
}
int find_diameter(){
    dfs(1);
    crr = 0;
    dfs(longest);
    return crr;
}
void init(){
  adj.assign(n + 1, vector<pair<int, int>>());
  crr = 0;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  cin >> t;
  while(t--){
    cin >> n;
    init();
    for(int i = 0; i < n - 1; ++i){
      cin >> u >> v >> c;
      adj[u].emplace_back(v, c);
      adj[v].emplace_back(u, c);
    }
    cout << find_diameter() << '\n';
  }
  return 0;
}
