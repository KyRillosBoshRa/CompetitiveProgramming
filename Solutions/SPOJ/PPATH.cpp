#include<bits/stdc++.h>
using namespace std;

int t;
string a, b;
set<string> prime;
void pre(){
  for(int i = 1000; i < 10000; ++i){
    prime.insert(to_string(i));
    for(int j = 2; j * j <= i; ++j){
      if(i%j == 0){
        prime.erase(to_string(i));
        break;
      }
    }
  }
}
int bfs(){
  map<string, int> dist;
  dist[a] = 0;
  queue<string> q;
  q.push(a);
  while(!q.empty()){
    string s = q.front();
    q.pop();
    if(s == b) return dist[s];
    for(int i = 0; i < 4; ++i){
      for(int j = (i == 0); j < 10; ++j){
        string tmp = s;
        tmp[i] = j + '0';
        if(dist.find(tmp) != dist.end()) continue;
        if(prime.find(tmp) != prime.end()){
          dist[tmp] = dist[s] + 1;
          q.push(tmp);
        }
      }
    }
  }
  return -1;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  pre();
  cin >> t;
  while(t--){
    cin >> a >> b;
    int x = bfs();
    if(~x) cout << x << '\n';
    else cout << "Impossible\n";
  }
  return 0;
}
