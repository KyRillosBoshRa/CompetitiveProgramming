#include <bits/stdc++.h>
using namespace std;

int Z, L, I, M, c;
int f(int x){
  return (1LL * Z * x + I) % M;
}
int floydCycleFinding(int x0) { // function int f(int x) is defined earlier
  // 1st part: finding k*mu, hare’s speed is 2x tortoise’s
  int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
  // 2nd part: finding mu, hare and tortoise move at the same speed
  int mu = 0; hare = x0;
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
  // 3rd part: finding lambda, hare moves, tortoise stays
  int lambda = 1; hare = f(tortoise);
  while (tortoise != hare) { hare = f(hare); lambda++; }
  return lambda;
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);// freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  while(cin >> Z >> I >> M >> L && M){
    cout << "Case " << ++c << ": " << floydCycleFinding(L) << '\n';
  }
  return 0;
}
