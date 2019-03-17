#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, c;
struct e{
  int u, v, c;
  e(int u, int v, int c): u(u), v(v), c(c){}
  bool operator <(const e& b){
    return c < b.c;
  }
};
vector<e> edges;
struct DSU{
  vector<int> par, size;
  int CC;
  DSU(int n){
    CC = n;
    par.resize(n+1);
    size.assign(n+1, 1);
    iota(par.begin(), par.end(), 0);
  }
  int root(int a){
    return par[a] == a ? a: par[a] = root(par[a]);
  }
  void unite(int a,int b){
    a = root(a);
    b = root(b);
    if(a == b) return;
    if(size[a] < size[b]) swap(a,b);

    par[b] = a;
    size[a] += size[b];
    --CC;
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  int s = 0;
  while(cin >> n >> m && (n || m)){
    for(int i = 0; i < m; ++i){
      cin >> u >> v >> c;
      edges.emplace_back(u, v, c);
      s += c;
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int ans = 0;
    for(int i = 0; i < m; ++i){
        if(!dsu.same(edges[i].u, edges[i].v)){
          dsu.unite(edges[i].u, edges[i].v);
          s -= edges[i].c;
        }
    }cout << s << '\n';
  }
  return 0;
}
