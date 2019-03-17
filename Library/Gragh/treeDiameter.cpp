//weighted
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