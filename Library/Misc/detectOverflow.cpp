bool detect_overflow(unsigned long long a, unsigned long long b){
	unsigned long long res = a*b;
	return a != 0 && res / a != b;
}
