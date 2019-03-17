#include <bits/stdc++.h>

using namespace std;

long long a, b;
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  while(cin >> a >> b){
    cout << (a^b) << '\n';
  }
  return 0;
}
