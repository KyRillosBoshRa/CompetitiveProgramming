#include <bits/stdc++.h>
using namespace std;

int t, n, k, p, c;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  cin >> t;
  while(t--){
    cin >> n >> k >> p; --k;
    cout << "Case " << ++c << ": " << (k+p)%n+1 << '\n';
  }
  return 0;
}
