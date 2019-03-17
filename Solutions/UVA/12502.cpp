#include <bits/stdc++.h>
using namespace std;

int n;
const double eps = 1e-5;
double a, b, z;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  cin >> n;
  while(n--){
    cin >> a >> b >> z;
    double x = z/(a+b);
    cout << int(x*a + x*(a-b)+eps) << '\n';
  }
  return 0;
}
