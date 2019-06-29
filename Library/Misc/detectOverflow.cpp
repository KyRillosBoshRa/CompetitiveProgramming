bool detect_overflow(unsigned long long a, unsigned long long b) {
  unsigned long long res = a * b;
  return a != 0 && res / a != b;
}

__builtin_umulll_overflow(unsigned long long int a, unsigned long long int b, unsigned long long int *res)