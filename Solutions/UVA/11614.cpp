#include <bits/stdc++.h>
using namespace std;

int t;
long long n;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  cin >> t;
  while(t--){
    cin >> n;
    long long l = 0, r = 1e10;
    while(l < r){
      long long mid = (l+r+1) >> 1;
      long long a = mid*(mid+1);
      if(mid && a / mid != mid+1){
        r = mid-1;
      }else if(a/2 > n){
        r = mid-1;
      }else{
        l = mid;
      }
    }cout << l << '\n';
  }
  return 0;
}
