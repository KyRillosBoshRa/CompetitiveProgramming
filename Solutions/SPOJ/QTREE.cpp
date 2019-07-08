#include <bits/stdc++.h>
using namespace std;

int n, t, u, v, c;
string s;
class segTree {
 private:
  struct node {
    int x;
    node(int a = 0) : x(a) {}
  };
  node combine(const node& a, const node& b) { return node(max(a.x, b.x)); }

  vector<node> sg;
  int x;

 public:
  segTree(int n = 0) {
    x = n;
    sg.assign(4 * n, 0);
  }
  void update_range(int st, int ed, int val, int idx = 0, int l = 0, int r = n - 1) {
    if (l > r) return;
    if (ed < l || st > r) return;
    if (l >= st && r <= ed) {
      sg[idx].x = val;
      return;
    }
    int m = l + ((r - l) >> 1);

    update_range(st, ed, val, 2 * idx + 1, l, m);
    update_range(st, ed, val, 2 * idx + 2, m + 1, r);

    sg[idx] = combine(sg[2 * idx + 1], sg[2 * idx + 2]);
  }

  node query(int st, int ed, int idx = 0, int l = 0, int r = n - 1) {
    if (ed < l || st > r) return node();
    if (l >= st && r <= ed) return sg[idx];
    int m = l + ((r - l) >> 1);

    node prt1 = query(st, ed, 2 * idx + 1, l, m);
    node prt2 = query(st, ed, 2 * idx + 2, m + 1, r);
    return combine(prt1, prt2);
  }
};
// For values on edge
vector<int> edge_to;  // which end point used in directing the edge
vector<int> edge_cost;
struct HLD {
  int n, p, eid;
  vector<int> parent, depth, heavy, root, pos;
  const int isValueOnEdge = 1;         // switch to 0 for value on node
  vector<vector<pair<int, int>>> adj;  // undirected tree
  segTree sgTree;

  HLD(int n) {
    this->n = n;
    adj = vector<vector<pair<int, int>>>(n);
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    root = vector<int>(n);
    pos = vector<int>(n);
    sgTree = segTree(n);
    p = 0;
    eid = 0;
  }
  void add_edge(int u, int v) {
    adj[u].emplace_back(v, eid);
    adj[v].emplace_back(u, eid);
    ++eid;
  }
  int dfs(int v) {
    int size = 1, maxSubtree = 0;
    for (auto u : adj[v]) {
      if (u.first != parent[v]) {
        edge_to[u.second] = u.first;
        parent[u.first] = v, depth[u.first] = depth[v] + 1;
        int childTreeSize = dfs(u.first);
        if (childTreeSize > maxSubtree) heavy[v] = u.first, maxSubtree = childTreeSize;
        size += childTreeSize;
      }
    }
    return size;
  }
  void build() {
    int n = adj.size();
    parent[0] = -1, depth[0] = 0;
    dfs(0);

    // Connect chains to its root. Map chain to segment tree part
    for (int chainRoot = 0; chainRoot < n; ++chainRoot) {
      if (parent[chainRoot] == -1 || heavy[parent[chainRoot]] != chainRoot) {
        for (int j = chainRoot; j != -1; j = heavy[j])  // iterate on a chain
          root[j] = chainRoot, pos[j] = p++;
      }
    }
  }

  int query(int u, int v) {
    int res = 0;
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth[root[u]] > depth[root[v]]) swap(u, v);
      int c_res = sgTree.query(pos[root[v]], pos[v]).x;
      res = max(res, c_res);
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (!isValueOnEdge || u != v) {
      int c_res = sgTree.query(pos[u] + isValueOnEdge, pos[v]).x;
      res = max(res, c_res);
    }
    return res;
  }
  // For value on DIRECTED edge (f, t, value), call update_node(t, value)
  void updatePos(int v, int val) { sgTree.update_range(pos[v], pos[v], val); }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif  // ONLINE_JUDGE
  cin >> t;
  while (t--) {
    cin >> n;
    edge_cost = edge_to = vector<int>(n);
    HLD hld(n);
    for (int i = 0; i < n - 1; ++i) {
      cin >> u >> v >> c;
      hld.add_edge(u - 1, v - 1);
      edge_cost[i] = c;
    }
    hld.build();
    for (int i = 0; i < n - 1; ++i) hld.updatePos(edge_to[i], edge_cost[i]);
    cin >> s;
    while (s != "DONE") {
      cin >> u >> v;
      if (s == "QUERY") {
        cout << hld.query(u - 1, v - 1) << '\n';
      } else {
        hld.updatePos(edge_to[u - 1], v);
      }
      cin >> s;
    }
  }
  return 0;
}