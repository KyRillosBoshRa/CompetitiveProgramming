#include <bits/stdc++.h>
using namespace std;

int r, n, c;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> r >> n && (r || n)){
    cout << "Case " << ++c << ": ";
    if((r+n-1) / n <= 27) cout << (r+n-1) / n - 1 << '\n';
    else cout << "impossible\n";  
  }
  return 0;
}
