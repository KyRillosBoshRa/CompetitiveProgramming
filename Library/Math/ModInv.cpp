int inv[N];
inv[1] = 1;
for (int i = 2; i < N; ++i)
	inv[i] = (N - (N / i) * inv[N % i] % N) % N;
_______________________________________________________
long long pow(long long x, long long e, int mod){
  a %= mod;
	long long res = 1;
	while(e){
    if(e & 1) res = (res * a) % mod;
		a = (a * a) % mod;
    e >>= 1;
  }
  return res;
}

long long modular_inverse(long long n, int mod){
	return pow(n % mod, mod-2, mod);
}
