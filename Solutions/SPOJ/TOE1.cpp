#include<bits/stdc++.h>
using namespace std;

string a[3];
int t;
bool win(char x){
  if(a[0][0] == x && a[0][0] == a[0][1] && a[0][0] == a[0][2]) return true;
  if(a[0][0] == x && a[0][0] == a[1][0] && a[0][0] == a[2][0]) return true;
  if(a[0][0] == x && a[0][0] == a[1][1] && a[0][0] == a[2][2]) return true;

  if(a[0][2] == x && a[0][2] == a[1][2] && a[0][2] == a[2][2]) return true;
  if(a[0][2] == x && a[0][2] == a[1][1] && a[0][2] == a[2][0]) return true;

  if(a[2][2] == x && a[2][2] == a[2][1] && a[2][2] == a[2][0]) return true;

  if(a[1][0] == x && a[1][0] == a[1][1] && a[1][0] == a[1][2]) return true;

  if(a[0][1] == x && a[0][1] == a[1][1] && a[0][1] == a[2][1]) return true;
  return false;
}
int count(char x){
  int res = 0;
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      res += (a[i][j] == x);
    }
  }
  return res;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  cin >> t;
  while(t--){
    for(int i = 0; i < 3; ++i) cin >> a[i];
    if(win('X') && win('O')) cout << "no\n";
    else if(win('X') && count('X') == count('O') + 1) cout << "yes\n";
    else if(win('O') && count('X') == count('O')) cout << "yes\n";
    else if(!(win('X') || win('O')) && (count('X') - count('O') == 0 || count('X') - count('O') == 1)) cout << "yes\n";
    else cout << "no\n";
  }
  return 0;
}
