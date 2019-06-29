// complexity is at most log(x)
const int N = 1e6 + 6;
int first_factor[N], p[N];
void primes() {
  first_factor[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (!p[i]) {
      first_factor[i] = i;
      for (int j = i * 2; j < N; ++j) {
        if (!first_factor[j]) {
          first_factor[j] = i;
          p[j] = 1;
        }
      }
    }
  }
}
vector<int> get_factors(int x) {
  vector<int> res;
  while (first_factor[x] != x) {
    res.push_back(first_factor[x]);
    x /= first_factor[x];
  }
  if (x != 1) res.push_back(x);
  sort(res.begin(), res.end());
  res.resize(unique(res.begin(), res.end()));
  return res;
}