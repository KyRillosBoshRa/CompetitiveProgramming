#include <bits/stdc++.h>
using namespace std;

int n, freq[10], t;
void add(int x){
  while(x){
    ++freq[x%10];
    x /= 10;
  }
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);// freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
  cin >> t;
  while(t--){
    cin >> n;
    memset(freq, 0, sizeof(freq));
    for(int i = 1; i <= n; ++i)
      add(i);
    for(int i = 0; i < 10; ++i)
      cout << freq[i] << " \n"[i == 9];
  }
  return 0;
}
