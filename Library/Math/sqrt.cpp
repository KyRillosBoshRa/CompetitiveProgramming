long long sqrt(long long a) {
  long long lo = 0, hi = 1e9 + 5;
  while (lo < hi - 1) {
    long long mid = lo + (hi - lo) >> 1;
    if (mid * mid > a)
      hi = mid;
    else
      lo = mid;
  }
  return lo;
}
