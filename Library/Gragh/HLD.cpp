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
        if (childTreeSize > maxSubtree)
          heavy[v] = u.first, maxSubtree = childTreeSize;
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