#include <bits/stdc++.h>

using namespace std;

long long d, u, v;
int t;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  cin >> t;
  for(int c = 1; c <= t; ++c){
    cin >> d >> v >> u;
    if(v >= u || !v || !u){
      cout << "Case " << c << ": can't determine\n";
      continue;
    }
    double a = 1.0*d/u;
    double b = d/sqrt(u*u-v*v);
    cout << "Case " << c << ": " << fixed << setprecision(3) << fabs(a-b) << '\n';
  }
  return 0;
}
