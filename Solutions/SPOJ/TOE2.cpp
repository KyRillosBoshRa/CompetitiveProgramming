//see TOE1 too
#include<bits/stdc++.h>
using namespace std;

char a[4][4];
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
  while(true){
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j){
        cin >> a[i][j];
        if(a[i][j] == 'e') exit(0);
      }
    }
    if(win('X') && !win('O') && count('X') == count('O') + 1) cout << "valid\n";
    else if(win('O') && !win('X') && count('X') == count('O')) cout << "valid\n";
    else if(!(win('X') || win('O')) && count('X') == 5 &&  count('O') == 4) cout << "valid\n";
    else cout << "invalid\n";
  }
  return 0;
}
