const int N = 1e6 + 5, p = 31, m = 1e9 + 9;
long long p_pow[N];
vector<int> rabin_karp(const string& s, const string& t) {
  int S = s.size(), T = t.size();

  vector<long long> h(T + 1, 0);
  for (int i = 0; i < T; i++)
    h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
  long long h_s = 0;
  for (int i = 0; i < S; i++) h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

  vector<int> occurences;
  for (int i = 0; i + S - 1 < T; i++) {
    long long cur_h = (h[i + S] + m - h[i]) % m;
    if (cur_h == h_s * p_pow[i] % m) occurences.push_back(i);
  }
  return occurences;
}