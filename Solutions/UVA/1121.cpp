#include <bits/stdc++.h>
using namespace std;

int n, m, a[100005];
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> n >> m){
    for(int i = 0; i < n; ++i) cin >> a[i];
    int ans = n + 1;
    int l = 0, r = 0;
    int sm = 0;
    while(l < n){
      while(r < n && sm < m) sm += a[r++];
      if(sm >= m) ans = min(ans, r - l);
      sm -= a[l++];
    }
    cout << (ans <= n ? ans: 0) << '\n';
  }
  return 0;
}
