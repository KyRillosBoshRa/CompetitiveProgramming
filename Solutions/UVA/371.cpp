#include <bits/stdc++.h>
using namespace std;

int s, e, mx, val;
int solve(long long x){
  if(x == 1) return 0;
  if(x&1) return 1+solve(3*x+1);
  else return 1+solve(x/2);
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);// freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> s >> e && (s || e)){
    if(s > e) swap(s, e);
    mx = val = -1;
    for(int i = s; i <= e; ++i){
      int tmp;
      if(i == 1) tmp = 3;
      else tmp = solve(i);
      if(tmp > mx){
        mx = tmp;
        val = i;
      }
    }
    cout << "Between " << s << " and " << e << ", " << val << " generates the longest sequence of " << mx << " values.\n";
  }
  return 0;
}
