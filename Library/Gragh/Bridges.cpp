// this can handle multi edges because we give to every edge certain id
const int N = 1e5 + 5;
int n, m, u, v;
vector<pair<int, int>> adj[N];  // node and edge id
int dfs_low[N], dfs_num[N], dfs_cnt;
vector<int> bridges;
void Find_Bridges(int v, int id = -1) {
  dfs_low[v] = dfs_num[v] = ++dfs_cnt;
  for (auto aa : adj[v]) {
    int u = aa.first;
    int ID = aa.second;
    if (!dfs_num[u]) {
      Find_Bridges(u, ID);
      dfs_low[v] = min(dfs_low[u], dfs_low[v]);
    } else if (ID != id) {
      dfs_low[v] = min(dfs_num[u], dfs_low[v]);
    }
  }
  if (dfs_low[v] == dfs_num[v] && ~id) {
    bridges.push_back(id);
  }
}