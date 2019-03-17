const int N = 1e5+5;
int n, m, u, v;
vector<int> adj[N];
vector<vector<int>> SCCs;
int dfs_low[N], dfs_num[N], dfs_cnt;
bool vis[N];
stack<int> stk;
void tarjanSCC(int v){
  dfs_low[v] = dfs_num[v] = ++dfs_cnt;
  stk.push(v);
  vis[v] = true;
  for(int u:adj[v]){
    if(!dfs_num[u]){
      tarjanSCC(u);
      dfs_low[v] = min(dfs_low[u], dfs_low[v]);
    }else if(vis[u]){
      dfs_low[v] = min(dfs_num[u], dfs_low[v]);
    }
  }
  if(dfs_low[v] == dfs_num[v]){
    SCCs.push_back(vector<int>());
    int x = -1;
    while(x != v){
      x = stk.top(); stk.pop();
      vis[x] = false;
      SCCs.back().push_back(x);
    }
  }
}