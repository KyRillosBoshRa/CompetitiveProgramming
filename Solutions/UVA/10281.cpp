#include <bits/stdc++.h>

using namespace std;

string S;
int tm, lstspeed, h, m, s, speed;
double km, lst;
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  while(getline(cin, S)){
    stringstream ss;
    char c;
    ss << S;
    if(S.size() > 8){
      ss >> h >> c >> m >> c >> s >> speed;
      double tmp = h+m/60.0+s/(60.0*60.0);
      km += (tmp-lst)*lstspeed;
      lst = tmp;
      lstspeed = speed;
    }else{
      ss >> h >> c >> m >> c >> s;
      double tmp = h+m/60.0+s/(60.0*60.0);
      km += (tmp-lst)*lstspeed;
      lst = tmp;
      cout << S << ' ' << fixed << setprecision(2) << km << " km\n";
      lst = h+m/60.0+s/(60.0*60.0);
    }
  }
  return 0;
}
