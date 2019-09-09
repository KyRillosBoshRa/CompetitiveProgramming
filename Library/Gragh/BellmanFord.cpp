struct edge {
  int a, b, cost;
  edge(int a = 0, int b = 0, int c = 0): a(a), b(b), cost(c){}
};

int n, m, v;
vector<edge> e;
const int INF = 1e9 + 9;

void bellman(int v) {
  vector<int> d(n, INF);
  d[v] = 0;
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < m; ++j)
      if (d[e[j].a] < INF) d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
}
