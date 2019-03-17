/*
  sort the input.. consider this element as the end of first dish
  add it to set loop throw second elements consider this element as the end of second dish
  add elements to set.. get the last element for third dish from the 2nd set
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, k;
pair<int, pair<int, int>> a[N];
multiset<pair<int, int>> st;
multiset<int> s;
long long ans = LLONG_MAX;
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second.first >> a[i].second.second;
  sort(a, a + n);
  for(int i = 0; i < n; ++i){
    st.insert(a[i].second);
    if(i < k - 1) continue;
    for(auto el: st){
      s.insert(el.second);
      if(s.size() > k) s.erase(--s.end());
      if(s.size() == k) ans = min(ans, 1LL * a[i].first + el.first + *s.rbegin());
    }
    s.clear();
  }cout << ans << '\n';
  return 0;
}
