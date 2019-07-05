class updRangeBIT {
 private:
  vector<long long> B1, B2;
  int cz;
  void update(vector<long long>& ft, int x, long long v) {
    for (; x < cz; x += (x & -x)) ft[x] += v;
  }

  long long query(int b) { return query(B1, b) * b - query(B2, b); }

  long long query(vector<long long>& ft, int b) {
    long long sum = 0;
    for (; b; b -= (b & -b)) sum += ft[b];
    return sum;
  }

 public:
  updRangeBIT(int n) {
    cz = n + 2;
    B1.assign(cz, 0);
    B2.assign(cz, 0);
  }

  long long range_query(int i, int j) {
    if (i == 1) return query(j);
    return query(j) - query(i - 1);
  }

  void range_update(int i, int j, long long v) {
    update(B1, i, v);
    update(B1, j + 1, -v);
    update(B2, i, v * (i - 1));
    update(B2, j + 1, -v * j);
  }
};