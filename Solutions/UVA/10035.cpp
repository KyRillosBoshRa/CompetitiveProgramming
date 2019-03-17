#include <bits/stdc++.h>
using namespace std;

long long a, b;
int add(long long x){
  int res = 0;
  while(x){
    res += x%10;
    x /= 10;
  }
  return res;
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> a >> b && (a || b)){
    int x = (add(a)+add(b)-add(a+b))/9;
    if(x == 1) cout << x << " carry operation.\n";
    else if(x) cout << x << " carry operations.\n";
    else cout << "No carry operation.\n";
  }
  return 0;
}
