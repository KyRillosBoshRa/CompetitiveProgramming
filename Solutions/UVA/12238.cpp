#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+55;
const int Nlog = log2(N)+5;
vector<vector<pair<int, int>>> adj;
int par[N][Nlog], h[N];
long long cost[N];
int n, m, q, u, v, c;
// 0 or 1 based
// memset par -1
void dfs(int v,int p = -1, long long c = 0){
	par[v][0] = p;
	if(~p) h[v] = h[p] + 1;
	cost[v] = c;
	for(int i = 1; i < Nlog; ++i)
		if(~par[v][i-1])
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u: adj[v])
    if(u.first != p)
      dfs(u.first, v, c + u.second);
}
int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = Nlog - 1; ~i; --i)
		if(~par[v][i] && h[par[v][i]] >= h[u])
			v = par[v][i];
	if(v == u)
		return v;
	for(int i = Nlog - 1;i >= 0;i --)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  while(cin >> n && n){
    adj.clear();
    adj.resize(n);
    memset(par, -1, sizeof(par));
    memset(cost, 0, sizeof(cost));
    memset(h, 0, sizeof(h));
    for(int i = 1; i < n; ++i){
      cin >> v >> c;
      adj[i].emplace_back(v, c);
      adj[v].emplace_back(i, c);
    }
    dfs(0);
    cin >> q;
    while(q--){
      cin >> u >> v;
      int l = LCA(u, v);
      cout << cost[u] + cost[v] - 2 * cost[l] << " \n"[!q];
    }
  }
  return 0;
}
