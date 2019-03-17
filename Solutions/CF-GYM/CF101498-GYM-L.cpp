#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 33;
int n, m, u[N * 10], v[N * 10], t;
long long dp[N], c[N * 10];
int main(){
//  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  scanf("%d", &t);
  while(t--){
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
      scanf("%d%d%lld", u + i, v + i, c + i);
    }
    int x;
    vector<long long> d(n + 1);
    for(int i = 0; i <= n; ++i){
      x = -1;
      for(int i = 0; i < m; ++i){
        if(d[u[i]] + c[i] < d[v[i]]) {
          d[v[i]] = d[u[i]] + c[i];
          x = 1;
        }
      }
    }
    if(~x){
      puts("-inf");
      goto lol;
    }
    for(int cnt = n + 1; ~cnt; --cnt){
      for(int i = 0; i < m; ++i){
        if(dp[v[i]] > c[i]) dp[v[i]] = c[i];
        if(dp[v[i]] > dp[u[i]] + c[i]) dp[v[i]] = dp[u[i]] + c[i];
      }
    }
    printf("%lld\n", *min_element(dp, dp + N));
    lol:;
  }
  return 0;
}