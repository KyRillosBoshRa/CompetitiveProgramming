#include <bits/stdc++.h>
using namespace std;

int n, ans;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> n && n){
    int x = 1;
    ans = 0;
    while(x <= n){
      ans += (n-x+1)*(n-x+1);
      ++x;
    }cout << ans << '\n';
  }
  return 0;
}
