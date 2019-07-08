#include <bits/stdc++.h>
using namespace std;

int n, t, u, v, c, q;
struct HLD {
  int n, p, eid;
  vector<set<pair<int, int>>> vs;
  vector<int> parent, depth, heavy, root;
  const int isValueOnEdge = 0;         // switch to 0 for value on node
  vector<vector<pair<int, int>>> adj;  // undirected tree

  HLD(int n) {
    this->n = n;
    adj = vector<vector<pair<int, int>>>(n);
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    root = vector<int>(n);
    vs = vector<set<pair<int, int>>>(n);
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
          root[j] = chainRoot;
      }
    }
  }

  int query(int u, int v = 0) {
    pair<int, int> res = {1e6, -2};
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth[root[u]] > depth[root[v]]) swap(u, v);
      int r = root[v];
      auto c_res = vs[r].begin();
      if (c_res != vs[r].end() && c_res->first < res.first &&
          depth[v] >= depth[c_res->second])
        res = *c_res;
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (!isValueOnEdge || u != v) {
      int r = root[v];
      auto c_res = vs[r].begin();
      if (c_res != vs[r].end() && c_res->first < res.first &&
          depth[v] >= depth[c_res->second])
        res = *c_res;
    }
    return res.second;
  }
  // For value on DIRECTED edge (f, t, value), call update_node(t, value)
  void updatePos(int v) {
    int r = root[v];
    auto it = vs[r].find({depth[v], v});
    if (it != vs[r].end()) {
      vs[r].erase(it);
    } else {
      vs[r].emplace(depth[v], v);
    }
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif  // ONLINE_JUDGE
  cin >> n >> q;
  HLD hld(n);
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    hld.add_edge(u - 1, v - 1);
  }
  hld.build();
  while (q--) {
    cin >> u >> v;
    if (u == 1) {
      cout << hld.query(v - 1) + 1 << '\n';
    } else {
      hld.updatePos(v - 1);
    }
  }
  return 0;
}