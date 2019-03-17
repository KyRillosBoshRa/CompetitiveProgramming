#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int t, n, a[N], c;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    cout << "Case " << ++c << ": " << a[n/2] << '\n';
  }
  return 0;
}
