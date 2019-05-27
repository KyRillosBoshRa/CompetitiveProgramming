const int N = 1e5+55;
const int Nlog = log2(N)+5;
vector<int> adj[N];
int par[N][Nlog], h[N];
// 0 or 1 based
// memset par -1
void dfs(int v,int p = -1){
	par[v][0] = p;
	if(~p) h[v] = h[p] + 1;
	for(int i = 1; i < Nlog; ++i)
		if(~par[v][i-1])
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : adj[v])
        if(u != p)
            dfs(u, v);
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
