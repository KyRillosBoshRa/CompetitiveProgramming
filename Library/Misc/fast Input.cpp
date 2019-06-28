#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif  // ONLINE_JUDGE
void nextInt(int &n) {
  char ch;
  short sign = 1;
  while (ch = gc(), isspace(ch)) {
  };
  n = 0;
  if (ch == '-')
    sign = -1;
  else
    n = ch - '0';
  while (ch = gc(), isdigit(ch)) n = (n << 3) + (n << 1) + ch - '0';
  n *= sign;
}