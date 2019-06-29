#define WHITE 0
#define GRAY 1
#define BLACK 2
const int N = 1e5 + 55;
int col[N];
vector<int> adj[N];
bool dfs(int v) {
  if (col[v]) return col[v] == GRAY;
  col[v] = GRAY;
  for (int u : adj[v])
    if (dfs(u)) return true;
  col[v] = BLACK;
  return false;
}
int par[N];
int cycle_start, cycle_end;
bool find_cycle(int v) {
  col[v] = GRAY;
  for (int u : adj[v]) {
    if (col[u] == WHITE) {
      par[u] = v;
      if (find_cycle(u)) return true;
    } else if (col[u] == GRAY) {
      cycle_start = u;
      cycle_end = v;
      return true;
    }
  }
  col[v] = BLACK;
  return false;
}