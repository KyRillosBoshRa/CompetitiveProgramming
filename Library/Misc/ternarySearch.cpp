while (lo < hi) {
  int mid = (lo + hi) >> 1;
  if (f(mid) > f(mid + 1)) {
    hi = mid;
  } else {
    lo = mid + 1;
  }
}