#include<bits/stdc++.h>
using namespace std;

const int N = 0x3f3f3f3f;
int a, b, c, t;
struct hsh{
  int operator()(const pair<int, int>& x) const{
    return x.first * 31 + x.second;
  }
};
int bfs(){
  queue<pair<int, int>> q;
  unordered_map<pair<int, int>, int, hsh> dist;
  q.emplace(0, 0);
  dist[{0, 0}] = 0;
  while(!q.empty()){
    int aa = q.front().first;
    int bb = q.front().second;
    q.pop();
    int xx = min(a - aa, bb);
    int yy = min(b - bb, aa);
//    cout << aa << ' ' << bb << ' ' << xx << ' ' << yy << '\n';
    if(aa == c || bb == c) return dist[{aa, bb}];
    if(dist.find({aa + xx, bb - xx}) == dist.end()) q.emplace(aa + xx, bb - xx),
      dist[{aa + xx, bb - xx}] = dist[{aa, bb}] + 1;
    if(dist.find({aa - yy, bb + yy}) == dist.end()) q.emplace(aa - yy, bb + yy),
      dist[{aa - yy, bb + yy}] = dist[{aa, bb}] + 1;
    if(dist.find({aa, 0}) == dist.end()) q.emplace(aa, 0),
      dist[{aa, 0}] = dist[{aa, bb}] + 1;
    if(dist.find({0, bb}) == dist.end()) q.emplace(0, bb),
      dist[{0, bb}] = dist[{aa, bb}] + 1;
    if(dist.find({a, bb}) == dist.end()) q.emplace(a, bb),
      dist[{a, bb}] = dist[{aa, bb}] + 1;
    if(dist.find({aa, b}) == dist.end()) q.emplace(aa, b),
      dist[{aa, b}] = dist[{aa, bb}] + 1;
  }
  return -1;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  cin >> t;
  while(t--){
    cin >> a >> b >> c;
    cout << bfs() << '\n';
  }
  return 0;
}
