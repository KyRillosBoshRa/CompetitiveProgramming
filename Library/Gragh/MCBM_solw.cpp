const int N = 3e5 + 5;
vector<int> adj[N], match, vis;
int n, s, vid = 1;

bool dfs(int v) {
  if (vis[v] == vid) return false;
  vis[v] = vid;
  for (int u : adj[v]) {
    if (!~match[u] || dfs(match[u])) {
      match[u] = v;
      return true;
    }
  }
  return false;
}

int MCBM() {
  match.assign(N + 1, -1);
  vis.assign(N + 1, 0);
  int ret = 0;
  for (int i = 0; i < s; ++i) {
    ret += dfs(i);
    ++vid;
  }
  return ret;
}