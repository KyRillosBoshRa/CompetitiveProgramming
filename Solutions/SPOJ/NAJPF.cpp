// Rabin Karp Algo
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 55, p = 31, mod = 1e9 + 9;
long long md(long long x) { return (x + mod) % mod; }
int t;
long long p_pow[N], x[N], y[N];
string a, b;
long long getl(int l, int r) { return md(x[r] - x[l - 1]); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif  // ONLINE_JUDGE
  cin >> t;
  bool fst = false;
  p_pow[0] = 1;
  for (int i = 1; i < N; ++i) p_pow[i] = (p_pow[i - 1] * p) % mod;
  while (t--) {
    cin >> a >> b;
    for (int i = 0; i < a.size(); ++i)
      x[i + 1] = (x[i] + p_pow[i] * (a[i] - 'a' + 1)) % mod;
    for (int i = 0; i < b.size(); ++i)
      y[i + 1] = (y[i] + p_pow[i] * (b[i] - 'a' + 1)) % mod;
    vector<int> ans;
    for (int i = b.size(); i <= a.size(); ++i)
      if (getl(i - b.size() + 1, i) ==
          (p_pow[i - b.size()] * y[b.size()]) % mod)
        ans.push_back(i - b.size() + 1);
    if (fst) cout << '\n';
    fst = true;
    if (ans.size()) {
      cout << ans.size() << '\n';
      for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
    } else {
      cout << "Not Found\n";
    }
  }
  return 0;
}
